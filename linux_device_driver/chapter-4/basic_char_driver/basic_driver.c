#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

#define BASENUM 0
#define DEVCOUNT 1

int mycdev_open(struct inode *, struct file *);
static ssize_t mycdev_read(struct file *, char __user *, size_t , loff_t *);

dev_t dev = -1;
int chrdev_open_counter = 0;

struct cdev *cdev;
struct class *mydev_class;

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = mycdev_open,
    .read = mycdev_read,
};

static int __init basic_chrdev_init(void)
{
    //Major Minor Number allocation for driver
    int ret_val = 0, ret;
    char chrdev_name[64] = "mychrdev";
    struct device *mychrdev;
    ret = alloc_chrdev_region(&dev, BASENUM, DEVCOUNT, chrdev_name);
    if(ret != 0){
        ret_val = 1;
        printk(KERN_ERR "Failed to allocate the Major and Minor Number");
        goto cleanup;
    }
    printk("Major No = %d  Minor No = %d\n", MAJOR(dev), MINOR(dev));
    
    //Create a char device
    mydev_class = class_create(THIS_MODULE, "chrdev_class");

    mychrdev = device_create(mydev_class, NULL, dev, NULL, chrdev_name);

    if(!mychrdev){
        printk(KERN_ERR "Creation of device failed\n");
        unregister_chrdev_region(dev, DEVCOUNT);
        ret_val = 1;
        goto cleanup;
    }

    //Initialize the cdev structure

    cdev = cdev_alloc();

    cdev_init(cdev, &fops);
    
    ret = cdev_add(cdev, dev, DEVCOUNT);
    if(ret != 0){
        printk("Failed to add the char device\n");
        device_destroy(mydev_class, dev);
        class_destroy(mydev_class);
        unregister_chrdev_region(dev, DEVCOUNT);
        ret_val = 1;
        goto cleanup;
    }
cleanup:
    return ret_val;
}

static void __exit basic_chrdev_exit(void)
{
    device_destroy(mydev_class, dev);
    class_destroy(mydev_class);
    cdev_del(cdev);
    unregister_chrdev_region(dev, DEVCOUNT);
}

int mycdev_open(struct inode *inode, struct file *fp)
{
    printk(KERN_INFO "Device opened Successfully\n");
    //Increamenting the counter every time device opened
    chrdev_open_counter++;
    printk(KERN_INFO "Device opened count = %d\n", chrdev_open_counter);
    printk(KERN_INFO "Device Major No = %d, Minor No = %d", MAJOR(dev), MINOR(dev));
    return 0;
}

static ssize_t mycdev_read(struct file *filp, char __user *buff, size_t lbuf, loff_t *ppos)
{
    char *kbuf;
    int kbuf_size = 100;
    ssize_t nbytes;
    kbuf = kmalloc(sizeof(char) * kbuf_size, GFP_KERNEL);
    memset(kbuf, 0x00, kbuf_size);
    strncpy(kbuf, "Hey Hiii Whats going on buddy", kbuf_size);
    nbytes = lbuf - copy_to_user(buff, kbuf + *ppos, lbuf);
    *ppos += nbytes;
    printk("No of bytes read = %zd, pos=%lld\n", nbytes, *ppos);
    return nbytes;
}

module_init(basic_chrdev_init);
module_exit(basic_chrdev_exit);
MODULE_AUTHOR("Mohit ARya");
MODULE_LICENSE("GPL");
