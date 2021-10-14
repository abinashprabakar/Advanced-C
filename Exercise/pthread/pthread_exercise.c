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

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

struct timespec tim;

void *thread1()
{
	int i;
//	int self_id = pthread_self();

	
	do
	{
		if(i%2 == 0)
		{
			printf("Thread -> %d\n",i);
			tim.tv_sec = 1;
			tim.tv_nsec = 0;
			nanosleep(&tim, NULL);
			i++;
		}
	}while(i < 61);
	pthread_exit(NULL);
}

void *thread2()
{
	int i;
//	int self_id = pthread_self();

	do
	{
		if(i%2 != 0)
		{
			printf("Thread -> %d\n",i);
			tim.tv_sec = 1;
			tim.tv_nsec = 0;
			nanosleep(&tim, NULL);
			i++;
		}
	}while(i < 61);
	pthread_exit(NULL);
}

int main()
{

	pthread_t t[2];
	pthread_create(&t[0], NULL, &thread1, NULL);
	pthread_create(&t[1], NULL, &thread2, NULL);

	return 0;
}
