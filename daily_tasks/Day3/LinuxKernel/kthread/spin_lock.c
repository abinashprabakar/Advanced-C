#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/spinlock.h>
#include <linux/delay.h>
#include <linux/sched.h>

static struct task_struct *thread_1;
static struct task_struct *thread_2;
static spinlock_t lock;
int shared = 0;

static int thread1_handler(void *ptr)
{
	while(!kthread_should_stop())
	{
		spin_lock(&lock);
		shared++;
		pr_info("thread 1 starts executing.. value: %d\n",shared);
		spin_unlock(&lock);
		ssleep(5);
	}

	return 0;
}

static int thread2_handler(void *ptr)
{
	while(!kthread_should_stop())
	{
		spin_lock(&lock);
		shared++;
		pr_info("thread 2 starts executing..value: %d\n",shared);
		spin_unlock(&lock);
		ssleep(5);
	}

	return 0;
}

static int my_mutex_test(void)
{
	thread_1 = kthread_create(thread1_handler,NULL,"my_thread_1");
	thread_2 = kthread_create(thread2_handler,NULL,"my_thread_2");

	if(thread_1 && thread_2)
	{
		wake_up_process(thread_1);
		wake_up_process(thread_2);
	}
	else
	{
		pr_info("threads not created..\n");
	}

	spin_lock_init(&lock);

	pr_info("test mutex module is loaded into kernel...\n");
	return 0;
}

static void my_mutex_cleanup(void)
{
	kthread_stop(thread_1);
	kthread_stop(thread_2);
	pr_info("test mutex module is unloaded from kernel..\n");
}

module_init(my_mutex_test);
module_exit(my_mutex_cleanup);

MODULE_LICENSE("GPL");

