/* Write a threaded program that does the following
   1. Prompts the user for the number of integers to enter
   2. Prompts the user for each integer and writes them into 
      a file named data.dat
   3. Determines how many integers are > 100
   4. Determines how many integers are < 100
   5. Outputs the total count for each group.

   The program should perform this task in the following way:
   Create a producer thread that:
   1. Prompts the user for the number of integers to enter
   2. Prompts the user for each integer and writes them into a file
      named data.dat
   Create a consumer thread that:
   1. Determines how many integers are > 100
   2. Outputs that value
   3. Sets that value to its exit value
   Create a consumer thread that:
   1. Determines how many integers are < 100
   2. Outputs that value
   3. Sets that value to its exit value
   Create a main thread that: 
   1. Creates threads 1 - 3
   2. Waits on the values of threads 2 and 3. 
   3. Outputs the values from threads 2 and 3.
 */

/* Include files */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
/* Problem 1. Add the necessary include files for this program */





/* 
   Global variables:
   We will need a mutex, a condition variable, and a predicate variable. 
   Recall that the predicate variable is the variable we use to determine
   whether data was available prior to our first call to pthread_cond_wait

 */

/* Problem 2. Declare the global variables for the predicate variable, 
   the mutex, and the condition variable. Do no forget to initialize 
   the mutex and the condition variable 
 */

int predicate;
pthread_cond_t var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;



/* This is a convenience function for dealing with errors
   and threads
 */

void hndlError(int error, const char *str)
{
  if (error == 0) return;
  errno = error;
  perror(str);
  exit(EXIT_FAILURE);
}


/* Define the three thread start functions. 
   You can name them whatever you wish 
 */

/* Problem 3. Define and write the start function for thread 1 */

void *thread1_handler(void *args)
{
	int n,i;
	FILE *fptr;
	pthread_t p1 = pthread_self();
	pthread_detach(p1);
	printf("Enter the number of integers to store: ");
	scanf("%d",&n);
	int arr[n];
	pthread_mutex_lock(&mutex);

	fptr = fopen("data.txt","w");

	printf("Enter the integers: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0;i<n;i++)
	{
		fprintf(fptr,"%d ",arr[i]);
	}

	fclose(fptr);

	predicate = 1;

	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&var);


	pthread_exit(NULL);


}

/* Problem 4. Define and write the start function for thread 2 */

void *thread2_handler()
{

	int *counter_1,k;
	counter_1 = (int *)malloc(sizeof(int));
	pthread_mutex_lock(&mutex);
	while(!predicate)
	{
		pthread_cond_wait(&var,&mutex);
	}

	


	
	FILE *fptr;

	fptr = fopen("data.txt","r");

	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&var);

	while(fscanf(fptr,"%d",&k)!=EOF)
	{
		if(k>100)
		{
			(*counter_1)++;
		}
	}
	fclose(fptr);
	
	printf("total larger: %d\n",*counter_1);
	pthread_exit((void *)counter_1);
}


/* Problem 5. Define and write the start function for thread 3 */

void *thread3_handler()
{
	int *counter,k;
	counter = (int *)malloc(sizeof(int));
	FILE *fptr;

	pthread_mutex_lock(&mutex);
	while(!predicate)
	{
		pthread_cond_wait(&var,&mutex);
	}

	fptr = fopen("data.txt","r");

	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&var);

	while(fscanf(fptr,"%d",&k)!=EOF)
	{
		if(k<100)
		{
			(*counter)++;
		}
	}
	fclose(fptr);
	

	printf("total smaller: %d\n",*counter);

	pthread_exit((void *)counter);

}


/* Problem 6: Define and write the function for the main thread */

int main(int argc, char *argv[])
{
	pthread_t t1,t2,t3;
	int *small,*large;

	pthread_create(&t3,NULL,thread3_handler,NULL);
	pthread_create(&t2,NULL,thread2_handler,NULL);
	pthread_create(&t1,NULL,thread1_handler,NULL);

	pthread_join(t2,(void **)&large);
	
	pthread_join(t3,(void **)&small);

	printf("smaller: %d\nlarger: %d\n",*small,*large);

	exit(EXIT_SUCCESS);
}
