#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prince K M <magics.com>");
MODULE_DESCRIPTION("Device Driver");
MODULE_VERSION("1.1");


ssize_t __device_read(struct file *fp, char *d, size_t size, loff_t *lt);
ssize_t __device_write(struct file *fp, const char *d, size_t size, loff_t *lt);
int __device_open(struct inode *ip,struct file *fp);
int __device_release(struct inode *ip,struct file *fp);

int __device_init(void);
void __device_exit(void);


struct file_operations device_functions={
    .open = __device_open,
    .release = __device_release,
    .read = __device_read,
    .write = __device_write,
};

int __device_open(struct inode *ip,struct file *fp){
   printk("open \n");
   return 0;
}

int __device_release(struct inode *ip,struct file *fp){
   printk("release \n");
   return 0;
}

ssize_t __device_read(struct file *fp, char *d, size_t size, loff_t *lt){
   printk("read \n");
   return 0;
}

ssize_t __device_write(struct file *fp, const char *d, size_t size, loff_t *lt){
   printk("write \n");
   return 0;
}

int __device_init(void){
   int major;
   major = register_chrdev(0,"devicename",&device_functions);
   if(major < 0)
          return -1;
   printk("init successfull with major :%d. \n",major);
          return 0;
}

void __device_exit(void){
   printk("exit successfull. \n");
}


module_init(__device_init);
module_exit(__device_exit);
