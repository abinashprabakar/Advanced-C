/* This program implements the creation of named pipe and writing data to it.
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 11.09.2021
 * Author : Abinash
 */

#include<stdio.h>	/* required for printf, fprintf, fflush, fopen, fclose */
#include<sys/stat.h>	/* required for S_IRWXU, S_IROTH */
#include<sys/types.h>

/* main program */

int main()
{
	FILE *fp;
	mkfifo("myfifo", S_IRWXU | S_IROTH);	/* creating namedpipe with only read permission to others */
	fp = fopen("myfifo", "w");	/* opening named pipe in write mode */
	fprintf(fp, "%s\n","hello...");	/* writing data to fifo */
	fflush(fp);	/* flushing the buffer pointed by fp so immediatly the data is written to named pipe myfifo */
	fclose(fp);	/* closing the file */
	return 0;
}
