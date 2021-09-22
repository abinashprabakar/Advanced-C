/* dup, dup2, dup3 - duplicate a file descriptor
 *
 *   The dup() system call allocates a new file descriptor that refers to the same open file description as 
 *   the descriptor oldfd.
 *
 *   The dup2() system call performs the same task as dup(), butinstead of using the lowest-numbered unused 
 *   file descriptor, it uses the file descriptor number specified in newfd.  In other words, the file descriptor
 *   newfd is adjusted so that it now refers to the same open file description as oldfd.
 *
 *   dup3() is the same as dup2(), except that. The caller can force the close-on-exec flag to be set for the
 *   new file descriptor by specifying O_CLOEXEC in flags.
 *    If oldfd equals newfd, then dup3() fails with the error EINVAL
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int old_fd, new_fd;
	old_fd = open("test.txt",O_RDONLY);
	printf("File descriptor : %d\n",old_fd);
	new_fd = dup(old_fd);
	printf("New file descriptor : %d\n",new_fd);
}
