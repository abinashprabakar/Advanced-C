/*  The dup2() system call performs the same task as dup(), but instead of using the lowest-numbered unused
 *  file descriptor, it uses the file descriptor number specified in newfd.  In other words, the file descriptor
 *  newfd is adjusted so that it now refers to the same open file description as oldfd.
 *
 *  Synopsis : int dup2(int oldfd, int newfd);
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int old_fd, new_fd;
	old_fd = open("test.txt",O_RDWR);
	printf("File descriptor : %d\n",old_fd);
	new_fd = dup2(old_fd, 7);
	printf("New file descriptor : %d\n",new_fd);
	return 0;
}
