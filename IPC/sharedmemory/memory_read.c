/* This program implements the reading of the data from shared memory segment
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 14.09.2021
 * Author : Abinash
 */

#include<stdio.h>   	/* required for printf() */
#include<sys/ipc.h>  	/* required for shared memory operations */
#include<sys/shm.h>  	/* required for shared memory operations */
#include<errno.h>    	/* required for strerror() */
#include<sys/stat.h>  	/* required for permission flag constants */

/* main program */
int main()
{
	int id;
	char *shared_memory;

	/* obtaining the shared memory ID */
	id = shmget(3434,0,IPC_CREAT|S_IRWXU);
	if(errno != 0)
	{
		printf("error occured at shmget: %s\n",strerror(errno));
	}
	/* attaching shared memory to program */
	shared_memory = shmat(id,NULL,0);

	if(errno != 0)
	{
		printf("error occured at shmat: %s\n",strerror(errno));
	}
	printf("data: %s\n",shared_memory);

	/* detaching shared memory */
	shmdt(shared_memory);
	return 0;
}
