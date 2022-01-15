#include<linux/module.h>
#include<linux/init.h>
#include<linux/spi/spi.h>

#define MY_BUS_NUM 0
static struct spi_device *bmp280_dev;

static int __init ModuleInit(void)
{
	struct spi_master *master;
	u8 id;
	u8 val = {0x75,0x40};

	/* spi device parameters */
	struct spi_board_info spi_device_info = 
	{
		.modalias = "bmp280",
		.max_speed_hz = 1000000,
		.bus_num = MY_BUS_NUM,
		.chip_select = 0,
		.mode = 3,
	};

	master = spi_busnum_to_master(MY_BUS_NUM);
	if(!master)
	{
		printk("No master device found \n");
		return -1;
	}

	bmp280_dev = spi_new_device(master, &spi_device_info);
	if(!bmp280_dev)
	{
		printk("Device creation failed\n");
		return -1;
	}

	bmp280_dev -> bits_per_word = 8;

	if(spi_setup(bmp280_dev) != 0)
	{
		printk("Could not change bus setup\n");
		spi_unregister_device(bmp280_dev);
		return -1;
	}

	id = spi_w8r8(bmp280_dev, 0xD0);
	printk("Chip id : 0x%x\n",id);

	spi_write(bmp280_dev, val, sizeof(8));
	id = spi_w8r8(bmp280_dev, 0xF5);
	printk("Config Reg. value : 0x%x\n",id);

	return 0;
}

static void __exit ModuleExit(void)
{
	if(bmp280_dev)
	{
		spi_unregister_device(bmp280_dev);
	}

}

MODULE_VERSION("1.1.1");
MODULE_DESCRIPTION("spi driver using bmp280 sensor");

module_init(ModuleInit);
module_exit(ModuleExit);
