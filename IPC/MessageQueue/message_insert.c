/* This program implements the operation of create the message queue and insert 1 message into message queue 
 * 
 * Email : abinashprabakaran@gmail.com
 * Date : 15.09.2021
 * Author : Abinash
 */

#include<stdio.h>     /* required for printf() */
#include<stdlib.h>    /* required for  */
#include<string.h>    /* required for strlen(), strcpy() */
#include<sys/ipc.h>   /* required for message queue operations */
#include<sys/msg.h>   /* required for message queue operations */
#include<sys/types.h> /* required for message queue operations */

/* defining size of message */
#define MSGSZ 128

/* declaring the message structure */

typedef struct msgbuf{
	long mtype;
	char mtext[MSGSZ];
}message_buf;

/* main program starts */
int main()
{
	int msqid;
	/* hold the message queue flags */
	int msgflg = IPC_CREAT | 0666;
	/* hold the key value */
	key_t key;
	/* hold the message */
	message_buf sbuf;
	size_t buf_length;

	/* initializing key value which should be unique */
	key = 2234;

	/* creating message queue */
	msqid = msgget(key,msgflg);
	if(msqid == -1)
	{
		perror("msgget");
		exit(1);
	}
	else
	{
		printf("message queue is created successfully..\n");
	}

	/* initializing message*/
	sbuf.mtype = 1;
	strcpy(sbuf.mtext,"Did you get this???");
	buf_length = strlen(sbuf.mtext)+1;

	/* sending message */
	if((msgsnd(msqid,&sbuf,buf_length,IPC_NOWAIT))<0)
	{
		printf("%d %ld %s %ld\n",msqid, sbuf.mtype, sbuf.mtext, buf_length);
		perror("msgsnd");
		exit(1);
	}
	else
	{
		printf("mesaage sent successfully..\n");
	}
	return 0;
}