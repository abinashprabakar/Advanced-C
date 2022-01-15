#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched.h>

static struct task_struct *thread_1;


static int my_handler(void *ptr)
{
	while(!kthread_should_stop())
	{
		pr_info("thread handeler is called..\n");
		ssleep(5);
	}
	return 0;
}

static int my_thread_start(void)
{
	thread_1 = kthread_create(my_handler,NULL,"my_thread_1");

	if(thread_1)
	{
		wake_up_process(thread_1);
	}
	else
	{
		pr_info("thread is not created..\n");
	}

	return 0;
}


static void my_thread_cleanup(void)
{
	kthread_stop(thread_1);
}

module_init(my_thread_start);
module_exit(my_thread_cleanup);

MODULE_LICENSE("GPL");

