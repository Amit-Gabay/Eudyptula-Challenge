#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <asm/delay.h>
#include <linux/slab.h>

static int do_work(int *my_int, int retval)
{
	int x;
	int y = *my_int;
	int z;
	
	for (x=0; x < *my_int; ++x)
		udelay(10);

	if (y < 10)
		pr_info("We slept a long time!");

	z = x * y;

	return z;
}

static int __init my_init(void)
{
	int x = 10;

	x = do_work(&x, x);

	return 0;
}

static void __exit my_exit(void)
{
	return;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL v2");
