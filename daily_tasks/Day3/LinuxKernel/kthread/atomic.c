#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

atomic_t my_var;

static int my_atomic_start(void)
{
	pr_info("atomic ops module is loaded into kernel..\n");
	pr_info("Var: %u\n",atomic_read(&my_var));
	pr_info("performing atomic addition..\n");
	atomic_add(10,&my_var);
	pr_info("var: %u\n",atomic_read(&my_var));
	pr_info("performing atomic subtraction..\n");
	atomic_sub(2,&my_var);
	pr_info("var: %u\n",atomic_read(&my_var));

	return 0;
}

static void my_atomic_cleanup(void)
{
	pr_info("my atomic ops module is unloaded from kernel..\n");
}

module_init(my_atomic_start);
module_exit(my_atomic_cleanup);

MODULE_LICENSE("GPL");
