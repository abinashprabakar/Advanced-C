/* This program implements the communication between the process created by fork through named pipe mechanism
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 11.09.2021
 * Author : Abinash
 */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

/* main program */
int main()
{
	int fd;
	mkfifo("myfifo", 0666);	/* creating read & write file */
	char s1[30], s2[30];

	if(fork() == 0)	/* child process */
	{
		fd = open("myfifo", O_WRONLY);	/* opening in write mode */
		fgets(s1, 30, stdin);		/* getting input from stdin */

		write(fd, s1, strlen(s1)+1);	/* writing data from s1 to fd */
		close(fd);
	}

	else		/* parent process */
	{
		fd = open("myfifo", O_RDONLY);	/* opening in read mode */
		read(fd, s2, 20);
		printf("Data from child : %s\n",s2);
		close(fd);
	}
	return 0;
}
