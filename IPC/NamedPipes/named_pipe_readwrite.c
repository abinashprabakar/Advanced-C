/* This program implements the reading and writing of the opened named pipe (FIFO)
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 11.09.2021
 * Author : Abinash
 */

#include<stdio.h>	/* required for printf, fgets */ 
#include<string.h>	/* required for string operation */
#include<fcntl.h>	/* required for open, close */
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>	/* required for read, write */

/* main program */
int main()
{
	int fd;
	mkfifo("myfifo", 0666);	/* creating read&write (0666) file using mkfifo */
	char s1[50], s2[50];
	while(1)
	{
		/* opening the file FIFO in read mode */
		fd = open("myfifo", O_RDONLY);
		read(fd, s1, 50);	/* reading data from FIFO */
		printf("user 1: %s\n",s1);	/* printing the data from FIFO */
		close(fd);	/* closing the file */

		/* opening the File in write mode */
		fd = open("myfifo", O_WRONLY);
		fgets(s2, 50, stdin);
		write(fd, s2, 50);	/* writing data to s2 */
		close(fd);	/* closing the file */
	}
	return 0;
}

