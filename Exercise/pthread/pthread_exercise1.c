/* For this exercise, we will be using pthread_create, pthread_exit, pthread_detach, pthread_self,
 * as well as nanosleep.
 *
 * The goal of this program is simple, create two threads that each output integers from 0 to 60. Each thread
 * should detach itself upon creation. Detached threads should use pthread_exit(NULL) to terminate.
 *
 * One thread should output an even integer every 1 second. Start these integers at 0 and stop at 60.
 *
 * The other thread should output an odd integer every 1 second. Start these integers at 1 and stop at 60.
 *
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 12.10.2021
 * Author : Abinash 
 */



#include<stdlib.h>
#include<time.h>	/* required for timespec */
#include<stdio.h>	/* required for printf */
#include<pthread.h>	/* required for pthread */

pthread_mutex_t lock;	/* the calling thread shall block until the mutex becomes available */
pthread_cond_t cond;
pthread_t tid[2];	/* thread id */
pthread_mutex_t mutex;

unsigned int data = 0, rc;

struct timespec tim;	/* structure to hold data such as time */

void* PrintEven(void*);	/* printEven function declaration */	
void* PrintOdd(void*);	/* printOdd function declaration */

/* main program */
int main(int argc,char **argv)
{
	pthread_create(&tid[0],0,&PrintEven,0);		/* thread creation */	
	pthread_create(&tid[1],0,&PrintOdd,0);		/* thread creation */

	pthread_detach(pthread_self());			/* detaching thread with pthread_self */
	pthread_exit(NULL);				/* thread exit */
}

void* PrintEven(void *pt00r)
{
	rc = pthread_mutex_lock(&lock);			/* locks the mutex */
	do
	{
		/* checking whether the data is even */
		if(data%2 == 0)
		{
	   /* blocks the calling thread, waiting for the condition specified by cond to be signaled or broadcast to */
			pthread_cond_wait(&cond,&lock);
			tim.tv_sec =1;			/* time for 1 second */
			tim.tv_nsec =0;			
			nanosleep(&tim,NULL);		/* suspends the execution of the calling thread for 1 sec */

			printf("Even: %d\n",data);
			data++;				/* increment data */
		}
		else
		{
			pthread_cond_signal(&cond);	/* unblocks the thread */
		}
		rc=pthread_mutex_unlock(&lock);	/* if number is odd, do not print, release mutex */

	} while (data < 61);
}

void* PrintOdd(void* ptr)
{
	rc = pthread_mutex_lock(&lock);			/* locks the mutex */
	do
	{
		if(data%2 != 0)
		{
			pthread_cond_wait(&cond,&lock);
			tim.tv_sec = 1;			/* time for 1 sec */
			tim.tv_nsec = 0;
			nanosleep(&tim, NULL);		/* suspends the calling thread for 1 sec */

			printf("Odd: %d\n",data);	
			data++;				/* increment data */
		}
		else
		{
			pthread_cond_signal(&cond);	/* unblocks the thread */
		}
		rc = pthread_mutex_unlock(&lock);	/* if number is even, do not print, release mutex */

	} while (data < 61);
}

