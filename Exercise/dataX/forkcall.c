#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

/* main program */
int main()
{
	pid_t cpid;	/* hold the process id */
	int num, status, i, k, avg = 0;
	char fname[256];

	FILE *fp;

	cpid = fork();

	if(cpid == 0)
	{
		char *arg[] = {"myRand",NULL};
		execl("./myRand",arg);
	}
	else
	{
		wait(&status);
		k = WEXITSTATUS(status);
	}

	sprintf(fname, "data%d.dat",k);

	fp = fopen(fname, "r");

	if(fp == NULL)
	{
		printf("Error : File does not exist\n");
		exit(0);
	}

	for(i=0; i<60; i++)
	{
		fscanf(fp, "%d",&num);
		printf("%d ",num);
		avg += num;
	}

	printf("\nAverage : %d\n",avg/60);
	fclose(fp);
	return 0;
}
