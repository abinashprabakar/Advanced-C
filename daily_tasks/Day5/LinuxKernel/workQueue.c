#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/workqueue.h>


void workqueue_handler(struct work_struct *work)
{
	pr_info("Executing workqueue function..\n");
}


DECLARE_WORK(my_workqueue,workqueue_handler);

static int workqueue_startup(void)
{
	schedule_work(&my_workqueue);

	pr_info("Work Queue loaded into kernel\n");
	return 0;
}

static void workqueue_cleanup(void)
{
	flush_work(&my_workqueue);
	pr_info("Work Queue unloaded from kernel\n");
}#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>

MODULE_LICENSE("GPL");

void workqueue_fn(struct work_struct *work); 
 
/*Creating work by Static Method */
DECLARE_DELAYED_WORK(workqueue,workqueue_fn);

/*Workqueue Function*/
void workqueue_fn(struct work_struct *work)
{
        printk(KERN_INFO "Executing Workqueue Function\n");
}

static int hello_tasklet_init(void)
{
	printk("module init start. \n");
	schedule_delayed_work(&workqueue,HZ*3);
	return 0;
}

static void hello_tasklet_exit(void)
{
	flush_delayed_work(&workqueue);
	printk("Goodbye, tasklet!\n");
}

module_init(hello_tasklet_init);
module_exit(hello_tasklet_exit);


module_init(workqueue_startup);
module_exit(workqueue_cleanup);

MODULE_LICENSE("GPL");

