
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/uaccess.h>


static const struct i2c_device_id device_id_table[] = {
    {"udhay_i2c",0},
    {},
};

static int major;
static struct class *i2c_test_cls;
static struct device *i2c_test_dev;
static const char* CLASS_NAME = "I2C_TEST_CLASS";
static const char* DEVICE_NAME = "I2C_TEST_DEVICE";

static struct i2c_client *_client;


static int i2c_test_open(struct inode *node, struct file *file)
{
    printk(KERN_ALERT "i2c init \n");
    return 0;
}

static ssize_t i2c_test_read(struct file *file,char *buf, size_t len,loff_t *offset)
{
    int cnt = 0;
    uint8_t reg = 0;
    uint8_t val = 0;
    copy_from_user(&reg,buf,1);
         /*i2c read byte, this function can read data from the specified address in the device*/
    val = i2c_smbus_read_byte_data(_client,reg);
    cnt = copy_to_user(&buf[1],&val,1);
    return 1;
}

static ssize_t i2c_test_write(struct file *file,const char *buf,size_t len,loff_t *offset)
{
    uint8_t recv_msg[255] = {0};
    uint8_t reg = 0;
    int cnt = 0;
    cnt = copy_from_user(recv_msg,buf,len);
    reg = recv_msg[0];
    printk(KERN_INFO "recv data = %x.%x\n",recv_msg[0],recv_msg[1]);
         /*i2c write byte, this function can write data to the specified address in the device*/
    if(i2c_smbus_write_byte_data(_client,reg,recv_msg[1]) < 0){
        printk(KERN_ALERT  " write failed!!!\n");
        return -EIO;
    }
    return len;
}

static int i2c_test_release(struct inode *node,struct file *file)
{
    printk(KERN_INFO "Release!!\n");
    
    return 0;
}

static struct file_operations file_oprts = 
{
    .open = i2c_test_open,
    .read = i2c_test_read,
    .write = i2c_test_write,
    .release = i2c_test_release,
};


static int _probe(struct i2c_client *client, const struct i2c_device_id *id)
{
         /*Save the parameter client, this parameter is needed in i2c read and write operations, which saves the adapter, device address and other information*/
    printk(KERN_ALERT "addr = %x\n",client->addr);
    _client = client;
    major = register_chrdev(0,DEVICE_NAME,&file_oprts);
    if(major < 0 ){
        printk(KERN_ALERT "Register failed!!\r\n");
        return major;
    }
    printk(KERN_ALERT "Registe success,major number is %d\r\n",major);

         /*Create a class structure with CLASS_NAME, this action will create a directory named CLASS_NAME in the /sys/class directory*/
    i2c_test_cls = class_create(THIS_MODULE,CLASS_NAME);
    if(IS_ERR(i2c_test_cls))
    {
        unregister_chrdev(major,DEVICE_NAME);
        return PTR_ERR(i2c_test_cls);
    }

         /*Use DEVICE_NAME as the name, refer to /sys/class/CLASS_NAME to create a device in the /dev directory: /dev/DEVICE_NAME*/
    i2c_test_dev = device_create(i2c_test_cls,NULL,MKDEV(major,0),NULL,DEVICE_NAME);
    if(IS_ERR(i2c_test_dev))
    {
        class_destroy(i2c_test_cls);
        unregister_chrdev(major,DEVICE_NAME);
        return PTR_ERR(i2c_test_dev);
    }
    printk(KERN_ALERT "i2c_test device init success!!\r\n");
    return 0;
}


static int _remove(struct i2c_client *client)
{
    printk(KERN_ALERT  "remove!!!\n");
    device_destroy(i2c_test_cls,MKDEV(major,0));
    class_unregister(i2c_test_cls);
    class_destroy(i2c_test_cls);
    unregister_chrdev(major,DEVICE_NAME);
    return 0;
}

static struct i2c_driver i2c_drv = {
  //       The name element in /*.driver is only an identification, not as a name identification for bus matching*/
    .driver = {
        .name = "random_i2c_test_udhay",
        .owner = THIS_MODULE,
    },
    .probe = _probe,
    .remove = _remove,
         /*.id_table stores the driver name, which is used as the identification when bus matching*/
    .id_table = device_id_table,
 };


int i2c_drv_init(void)
{
    int ret = 0;
    printk(KERN_ALERT  "init!!!\n");
    ret  = i2c_add_driver(&i2c_drv);
    if(ret){
        printk(KERN_ALERT "add driver failed!!!\n");
        return -ENODEV;
    }
    return 0;
}


void i2c_drv_exit(void)
{
    i2c_del_driver(&i2c_drv);
    return ;
}

MODULE_LICENSE("GPL");
module_init(i2c_drv_init);
module_exit(i2c_drv_exit);
