#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/completion.h>
#include <linux/delay.h>

DECLARE_COMPLETION(my_var);

static struct task_struct *thread_1;

static int thread_handler(void *ptr)
{
	pr_info("thread hanlder is called..\n");

	pr_info("waiting for event..\n");
	wait_for_completion(&my_var);
	
	pr_info("event is happened..\n");
	return 0;
}

static int my_completion_startup(void)
{
	thread_1 = kthread_create(thread_handler,NULL,"my_thread1");
	if(thread_1)
	{
		pr_info("thread created successfully..\n");
		wake_up_process(thread_1);
	}
	else
	{
		pr_info("thread creation failed..\n");
		return 0;
	}
	pr_info("Completion loaded into kernel\n");
	return 0;
}

static void my_completion_cleanup(void)
{
	if(! completion_done(&my_var))
	{
		complete(&my_var);
	}

	pr_info("Completion unloaded from kernel\n");
}


module_init(my_completion_startup);
module_exit(my_completion_cleanup);

MODULE_LICENSE("GPL");

