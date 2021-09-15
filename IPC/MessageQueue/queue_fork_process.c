/* This program implements the message queue operation using fork() system call
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 15.09.2021
 * Author : Abinash
 */

#include<stdio.h>     /* required for printf() */
#include<unistd.h>    /* required for fork() */
#include<stdlib.h>    /* required for exit */
#include<sys/ipc.h>   /* required for message queue operations*/
#include<sys/msg.h>   /* required for message queue operations */
#include<sys/wait.h>  /* required for waitpid() */
#include<string.h>    /* required for strlen(), strcpy() functions */

/* message structure */
struct message
{
	long type;
	char mtext[100];
};

/* main program */
int main()
{
	/* creating message queue */
	int msqid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
	/* on failure msgget function returns -1 */
	if(msqid == -1)
	{
		perror("msgget");
		return EXIT_FAILURE;
	}

	/* creating child process */
	pid_t pid = fork();
	
	if(pid == 0)
	{
		/* in child process */
		/* hold the message */
		struct message m1;
		/* initializing values */
		m1.type = 18;
		memset(&(m1.mtext),0,100*sizeof(char));
		strcpy(m1.mtext,"hello parent...\n");

		/* sending message to he queue */
		if(msgsnd(msqid,&m1,sizeof(long)+(strlen(m1.mtext))+1,0)==-1)
		{
			perror("msgsnd");
			return EXIT_FAILURE;
		}
	}
	else
	{
		/* in parent process */
		/* waiting for child to finsh its execution */
		waitpid(pid,NULL,0);

		/* receive message from queue */
		struct message m2;
		if(msgrcv(msqid,&m2,100,0,0)==-1)
		{
			perror("msgrcv");
			return EXIT_FAILURE;
		}

		/* printing received message from child */
		printf("%s\n",m2.mtext);

		/* destroy the message queue */
		if(msgctl(msqid,IPC_RMID,NULL)==-1)
		{
			perror("msgctl");
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
