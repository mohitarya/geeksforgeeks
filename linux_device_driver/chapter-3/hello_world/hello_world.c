#include <linux/module.h>
#include <linux/init.h>

int irq = 10;
/*
static int __init my_init(void)
{
    printk(KERN_INFO "My module %s\n", "Hello World");
    printk(KERN_INFO "IRQ value = %d\n", irq);
    return 0;
}
*/
static void __exit my_exit(void)
{
    printk(KERN_INFO "irq value at time of exit is %d\n", irq);
    printk(KERN_INFO "Exiting module Hello World\n");
}

//module_init(my_init);
module_exit(my_exit);
module_param(irq, int, 0644);
MODULE_AUTHOR("Mohit Arya");
MODULE_LICENSE("GPL");
