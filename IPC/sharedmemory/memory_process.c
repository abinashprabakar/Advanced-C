/* This program implements the attachement of shared memory to the process and put data into the shared memory
 *
 * Email : abinashprabakaran@gmail.com	
 * Date : 14.09.2021
 * Author : Abinash
 */

#include<stdio.h>   	/* required for printf() */
#include<sys/shm.h>   	/* required for shmat() shmdt() shmget() */
#include<sys/ipc.h>   	/* required for shared memory operations */
#include<errno.h>   	/* required for strerror() */
#include<sys/stat.h>  	/* required for permission flags */

/* main program */
int main()
{
	char *shared_memory;
	int id;
	/* referning to shared memory */
	id = shmget(3434,0,IPC_CREAT|S_IRWXU);
	
	if(errno != 0)
	{
		printf("Error occured in shmget: %s\n",strerror(errno));
	}
	
	/* attaching the shared memory segment */
	shared_memory = shmat(id,NULL,0);

	if(errno != 0)
	{
		printf("error occured at shmat: %s\n",strerror(errno));
	}
	/* writing data into shared memory segment */
	sprintf(shared_memory,"%s","Hello...world...\n");
	printf("some information writes in shared memory...\n");

	/* detaching the shared memory from process so it won't refer after*/
	shmdt(shared_memory);
	return 0;
}
