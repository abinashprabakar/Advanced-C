#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL");

static struct timer_list my_timer;
static void my_tasklet_handler(unsigned long flag);
static DECLARE_TASKLET_DISABLED_OLD(my_tasklet, my_tasklet_handler);

void my_timer_callback( struct timer_list *timer)
{
    pr_info( "%s called (%ld).\n", __FUNCTION__, jiffies );
    tasklet_schedule(&my_tasklet);
    mod_timer( &my_timer, jiffies + msecs_to_jiffies(3000) );
}

static void my_tasklet_handler(unsigned long flag)
{
	printk("my_tasklet run: do what the tasklet want to do....\n");
}

static int hello_tasklet_init(void)
{
	printk("module init start. \n");
	printk("Hello tasklet!\n");
	tasklet_enable(&my_tasklet);
	timer_setup( &my_timer, my_timer_callback, 0 );
	mod_timer( &my_timer, jiffies + msecs_to_jiffies(300) );
	printk("module init end.\n");
	return 0;
}

static void hello_tasklet_exit(void)
{
	tasklet_kill(&my_tasklet);
	del_timer( &my_timer );
	printk("Goodbye, tasklet!\n");
}

module_init(hello_tasklet_init);
module_exit(hello_tasklet_exit);
