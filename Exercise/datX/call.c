#include<stdio.h>	/* required for printf, scanf */
#include<sys/types.h>	/* required for pid_t */
#include<sys/wait.h>	/* required for WEXITSTATUS */
#include<string.h>	/* required for string operations */
#include<stdlib.h>

int main()
{
	pid_t cpid;	/* to represent process id */
	FILE *fp;
	int status, i, num, average=0, k;
	char *fname, *n;
	cpid = fork();	/* fork process created */

	if(cpid == 0)
	{
		char *arg[] = {"./myRand", NULL};
		execl("./myRand",arg);	/* replaced current process with new process by for function */
	}
	else
	{
		wait(&status);
		k = WEXITSTATUS(status);	/* returns the value of child process */
	}

	fname = (char *)malloc(sizeof(char));	/* allocating memory for fname */
	strcpy(fname, "data.dat");		/* copying data.dat to fname */
	if(asprintf(&n, "%d",k)==-1)
	{
		printf("Error: Can't able to exit\n");
		exit(0);
	}

	memmove(fname+7, fname+4, 5);		/* moving .dat to data */
	memmove(fname+4, n, 3);			

	fp = fopen(fname, "r");			/* opening file in read mode */
	if(fp == NULL)
	{
		printf("Error: Can't able to open file\n");
		exit(0);
	}

	/* Getting the data from data.dat file */
	for(i=0; i<60; i++)
	{
		fscanf(fp, "%d",&num);
		printf("%d ",num);
		average+=num;
	}
	printf("\n");

	printf("Average : %d\n",average/60);
	fclose(fp);	/* closing the file */

	return 0;
}
