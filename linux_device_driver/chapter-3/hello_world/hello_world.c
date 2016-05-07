#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void)
{
    printk(KERN_INFO "My module %s\n", "Hello World");
    return 0;
}

static void __exit my_exit(void)
{
    printk(KERN_INFO "Exiting module Hello World");
}

module_init(my_init);
module_exit(my_exit);
MODULE_AUTHOR("Mohit Arya");
MODULE_LICENSE("GPL");
