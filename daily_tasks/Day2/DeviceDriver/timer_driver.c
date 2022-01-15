#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/device.h>
#include<linux/timer.h>
#include<linux/kdev_t.h>
#include<linux/jiffies.h>
#include<linux/input.h>
#include<asm/io.h>

#define TIMEOUT 5000	
static struct timer_list custom_timer;
static struct input_dev *key_dev;

void timer_callback(struct timer_list *data)
{
	input_report_key(key_dev, KEY_A, 1);
	input_report_key(key_dev, KEY_A, 0);
	input_report_key(key_dev, KEY_B, 1);
	input_report_key(key_dev, KEY_B, 0);
	input_report_key(key_dev, KEY_C, 1);
	input_report_key(key_dev, KEY_C, 0);
	input_report_key(key_dev, KEY_D, 1);
	input_report_key(key_dev, KEY_D, 0);
	input_report_key(key_dev, KEY_E, 1);
	input_report_key(key_dev, KEY_E, 0);
	input_report_key(key_dev, KEY_F, 1);
	input_report_key(key_dev, KEY_F, 0);
	input_report_key(key_dev, KEY_G, 1);
	input_report_key(key_dev, KEY_G, 0);
	input_report_key(key_dev, KEY_H, 1);
	input_report_key(key_dev, KEY_H, 0);
	input_report_key(key_dev, KEY_I, 1);
	input_report_key(key_dev, KEY_I, 0);
	input_report_key(key_dev, KEY_J, 1);
	input_report_key(key_dev, KEY_J, 0);
	input_report_key(key_dev, KEY_K, 1);
	input_report_key(key_dev, KEY_K, 0);
	input_report_key(key_dev, KEY_L, 1);
	input_report_key(key_dev, KEY_L, 0);
	input_report_key(key_dev, KEY_M, 1);
	input_report_key(key_dev, KEY_M, 0);
	input_report_key(key_dev, KEY_N, 1);
	input_report_key(key_dev, KEY_N, 0);
	input_report_key(key_dev, KEY_O, 1);
	input_report_key(key_dev, KEY_O, 0);
	input_report_key(key_dev, KEY_P, 1);
	input_report_key(key_dev, KEY_P, 0);
	input_report_key(key_dev, KEY_Q, 1);
	input_report_key(key_dev, KEY_Q, 0);
	input_report_key(key_dev, KEY_R, 1);
	input_report_key(key_dev, KEY_R, 0);
	input_report_key(key_dev, KEY_S, 1);
	input_report_key(key_dev, KEY_S, 0);
	input_report_key(key_dev, KEY_T, 1);
	input_report_key(key_dev, KEY_T, 0);
	input_report_key(key_dev, KEY_U, 1);
	input_report_key(key_dev, KEY_U, 0);
	input_report_key(key_dev, KEY_V, 1);
	input_report_key(key_dev, KEY_V, 0);
	input_report_key(key_dev, KEY_W, 1);
	input_report_key(key_dev, KEY_W, 0);
	input_report_key(key_dev, KEY_X, 1);
	input_report_key(key_dev, KEY_X, 0);
	input_report_key(key_dev, KEY_Y, 1);
	input_report_key(key_dev, KEY_Y, 0);
	input_report_key(key_dev, KEY_Z, 1);
	input_report_key(key_dev, KEY_Z, 0);


	mod_timer(&custom_timer, jiffies + msecs_to_jiffies(TIMEOUT));
}

static int timer_init(void)
{
	key_dev = input_allocate_device();

	set_bit(EV_KEY,key_dev->evbit);

	set_bit(KEY_A,key_dev->keybit);
	set_bit(KEY_B,key_dev->keybit);
	set_bit(KEY_C,key_dev->keybit);
	set_bit(KEY_D,key_dev->keybit);
	set_bit(KEY_E,key_dev->keybit);
	set_bit(KEY_F,key_dev->keybit);
	set_bit(KEY_G,key_dev->keybit);
	set_bit(KEY_H,key_dev->keybit);
	set_bit(KEY_I,key_dev->keybit);
	set_bit(KEY_J,key_dev->keybit);
	set_bit(KEY_K,key_dev->keybit);
	set_bit(KEY_L,key_dev->keybit);
	set_bit(KEY_M,key_dev->keybit);
	set_bit(KEY_N,key_dev->keybit);
	set_bit(KEY_O,key_dev->keybit);
	set_bit(KEY_P,key_dev->keybit);
	set_bit(KEY_Q,key_dev->keybit);
	set_bit(KEY_R,key_dev->keybit);
	set_bit(KEY_S,key_dev->keybit);
	set_bit(KEY_T,key_dev->keybit);
	set_bit(KEY_U,key_dev->keybit);
	set_bit(KEY_V,key_dev->keybit);
	set_bit(KEY_W,key_dev->keybit);
	set_bit(KEY_X,key_dev->keybit);
	set_bit(KEY_Y,key_dev->keybit);
	set_bit(KEY_Z,key_dev->keybit);

	input_register_device(key_dev);

	timer_setup(&custom_timer, timer_callback, 0);
	mod_timer(&custom_timer, jiffies + msecs_to_jiffies(TIMEOUT));
	printk(KERN_INFO "Device Driver Insert...Done!!!\n");

	return 0;
}

static void timer_exit(void)
{
	del_timer(&custom_timer);
	input_unregister_device(key_dev);

	printk(KERN_INFO "Device Driver unloaded...Done!!!\n");
}


module_init(timer_init);
module_exit(timer_exit);

MODULE_AUTHOR("Timer");
MODULE_VERSION("1.1.1");
MODULE_LICENSE("GPL");
