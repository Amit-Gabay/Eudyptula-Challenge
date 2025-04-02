#include <linux/module.h>
#include <linux/init.h>
#include <linux/printk.h>

#define SUCCESS (0)

static int __init hello_init(void)
{
	printk(KERN_DEBUG "Hello World, from 0x%p\n", hello_init);
	return SUCCESS;
}

static void __exit hello_exit(void)
{
	printk(KERN_DEBUG "Goodbye World, from 0x%p\n", hello_exit);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Amit Gabay");
MODULE_DESCRIPTION("A PoC kernel module");
MODULE_LICENSE("GPL v2");
