/* Write a multiple concurrent process program that does the following
   1. Prompts the user for the number of integers to enter
   2. Prompts the user for each integer and writes them into 
      a file named data.dat
   3. Determines how many integers are > 100
   4. Determines how many integers are < 100
   5. Outputs the total count for each group.

   The program should perform this task in the following way:
   Create a producer child that:
   1. Prompts the user for the number of integers to enter
   2. Prompts the user for each integer and writes them into a file
      named data.dat
   Create a consumer child that:
   1. Determines how many integers are > 100
   2. Outputs that value
   3. Sets that value to its exit value
   Create a consumer child that:
   1. Determines how many integers are < 100
   2. Outputs that value
   3. Sets that value to its exit value
   Create a parent that: 
   1. Creates children 1 - 3
   2. Pauses. 
 */

/* Include files */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

/* Problem 1. Add the necessary include files for this program */



/* 
   Global variables:
   For this project I am storing the pid's of the three children
   and two integers that serve the role of flags and counters

 */

/* Problem 2. Declare the global variables for pid's of the three
   children and the two integers that serve the role of flags and
   counters. The first flag deals with the large count; the second
   flag deals with the small count.
 */
pid_t c1, c2, c3;
int large_count, small_count;
#define BUF_SIZE 1024


/* myPrint is a convenience function to use when we are in a signal 
   handler. This is because printf uses buffered I/O.
 */
void myPrint(const char *str)
{
	if (write(STDOUT_FILENO, str, strlen(str)) == -1)
    	{
      		perror("write");
      		exit(EXIT_FAILURE);
    	}
}

/* Signal handlers
   We will need to implement at least two signal handlers. 
   One for the parent and a minimum of one for the children
 */

/* Problem 3. Define and write the signal handler for the parent */

void handlerParent(int sig)
{
	if(sig == SIGUSR1)
		large_count++;

	else if(sig == SIGUSR2)
		small_count++;

	else if(sig == SIGCHLD)
	{
		wait(NULL);
		kill(c2, SIGUSR1);
		wait(NULL);
		kill(c3, SIGUSR1);
		wait(NULL);

		printf("Large count : %d\n Small count : %d\n",large_count, small_count);
		exit(EXIT_SUCCESS);
	}
}

/* Problem 4. Define and write the signal handler for the children */

void handlerChild(int sig)
{
	if(sig == SIGUSR1)
		large_count = 1;

	else if(sig == SIGUSR2)
		small_count = 1;
}

/* Functions for each of the children. 
   We will be writing functions for each of the three children.
   This should make it easier to answer the questions on threads.
 */

/* Problem 5. Define and write the function for child 1. */

void child1()
{
	int i,n;
	FILE *fptr;
	printf("Enter the integer size:");
	scanf("%d",&n);
	int arr[n];

	fptr = fopen("data.txt","w");

	printf("Enter %d numbers",n);
	for(i=0; i<n; i++)
		scanf("%d",arr[i]);

	for(i=0; i<n; i++)
		fprintf(fptr, "%d",arr[i]);

	fclose(fptr);
	
	exit(0);
}

/* Problem 6. Define and write the function for child 2. */

void child2()
{
	signal(SIGUSR1, handlerChild);
	while(!large_count);

	FILE *fptr;
	int k,counter=0;

	fptr = fopen("data.txt","w");

	while(fscanf(fptr,"%d",&k)!=EOF)
	{
		if(k>100)
		{
			counter++;
			kill(getppid(), SIGUSR1);
		}
	}

	fclose(fptr);
	printf("Large count : %d\n",counter);
	exit(0);
}

/* Problem 7. Define and write the function for child 3. */

void child3()
{
	signal(SIGUSR2, handlerChild);
	while(!small_count);

	FILE *fptr;
	int k,counter=0;

	fptr = fopen("data.txt","w");

	while(fscanf(fptr,"%d",&k)!=EOF)
	{
		if(k>100)
		{
			counter++;
			kill(getppid(), SIGUSR2);
		}
	}

	fclose(fptr);
	printf("Small count : %d\n",counter);
	exit(0);
}

/* This function forks a child and runs the function passed
   in after the child has successfully forked. I have provided
   it to make the code easier to read.
 */
pid_t hndlFork(void (*child)(void))
{
	pid_t p;
  	p = fork();
  
	if (p == -1)
    	{
      		perror("fork");
      		exit(EXIT_FAILURE);
    	}
  
	if (p == 0)
    	{
      		child();
    	}
  
	return p;
}

/* Problem 8: Define and write the function main */


int main(int argc, char *argv[])
{
	signal(SIGCHLD, handlerParent);

	c2 = hndlFork(child2);
	c3 = hndlFork(child3);

	signal(SIGUSR1, handlerParent);
	signal(SIGUSR2, handlerParent);

	c1 = hndlFork(child1);

	while(1);

	exit(EXIT_SUCCESS);
}
