#include <linux/module.h>
#include <linux/device.h>
#include <linux/err.h>

static int __init hello_world_init(void){
	printk("hello_world loaded\n");
	return(0);
}

static void __exit hello_world_exit(void){
	printk("hello_world terminated\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");

