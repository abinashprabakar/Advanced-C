
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/regmap.h>
// #include <linux/paltform_device.h>


static struct i2c_adapter *adap;
static struct i2c_client  *client;
#define  I2C_DEVICE_ADDR   0x68


static struct i2c_board_info device_id = {
    I2C_BOARD_INFO("udhay_i2c",I2C_DEVICE_ADDR),
};


static int i2c_dev_init(void)
{
         
    adap = i2c_get_adapter(2);
    if(IS_ERR(adap)){
        printk(KERN_ALERT  "I2c_get_adapter failed!!!\n");
        return -ENODEV;
    }
         /*Create an I2C device and register it in the device list of the i2c bus*/
    client = i2c_new_device(adap,&device_id);
         /*Enable the corresponding adapter*/
    i2c_put_adapter(adap);
    if(!client){
    printk(KERN_ALERT  "Get new device failed!!!\n");
    return -ENODEV;
    }
    return 0;
}

 void i2c_dev_exit(void)
{
    i2c_unregister_device(client);
    return ;
}

MODULE_LICENSE("GPL");
module_init(i2c_dev_init);
module_exit(i2c_dev_exit);
