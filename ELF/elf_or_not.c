/* This program implements the elf to check whether the file is elf or not
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 15.09.2021
 * Author : Abinash
 */

#include<stdio.h>     /* required for printf() */
#include<stdlib.h>    /* required for exit() */
#include<unistd.h>    /* required for test read permission */
#include<sys/stat.h>  /* required for file operations */
#include<fcntl.h>     /* required for file operations */

/* main program */
int main(int argc, char *argv[])
{
	/* checking for command line input is passed or not */
	if(argc<2)         
	{
		printf("Filename is missing....\n");
		exit(1);
	}

	int fd,data;
	
	/* opening input file in read only mode */
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		printf("faild to open file...\n");
		exit(1);
	}
	
	/* reading first 4 bytes data from the file */
	read(fd,&data,sizeof(data));
	
	/* checking inut file is elf or not */
	if(data == 0x464c457f)
	{
		printf("The file is ELF..\n");
	}
	else
	{
		printf("The file is not ELF...\n");
	}
	return 0;
}
