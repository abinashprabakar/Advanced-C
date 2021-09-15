/* This program implements the operation of creating the message queue and read the message from the mesaage queue
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 15.09.2021
 * Author : Abinash
 */

#include<stdio.h>     /* required for printf() */
#include<sys/ipc.h>   /* required for message queue operations */
#include<sys/msg.h>   /* required for message queue operations */
#include<sys/types.h> /* required for message queue operations */
#include<string.h>    /* required for strlen() */
#include<stdlib.h>    /* required for exit() */

/* defining the size of message */
#define MSGSZ 128

/* declaring message structure */
typedef struct msgbuf{
	long mtype;
	char mtext[MSGSZ];
}message_buf;

/* main program */
int main()
{
	
	int msqid;
	/* hold the key value */
	key_t key;
	/* hold the message */
	message_buf rbuf;

	key = 2234;

	/* creating message queue */
	msqid = msgget(key,0666);
	if(msqid == -1)
	{
		perror("msgget");
		exit(1);
	}

	/* reading message from message queue */
	if(msgrcv(msqid,&rbuf,MSGSZ,1,0)<0)
	{
		perror("msgrcv");
		exit(0);
	}

	/* printing the received message data */
	printf("%s\n",rbuf.mtext);
	return 0;
}
