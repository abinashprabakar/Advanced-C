#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<signal.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
/* Problem 1 – complete the list of include files */

#define BUF_SIZE 1024

static int timed;

/* the myPrint function takes a constant c-string
 * and outputs it to STDOUT using write
 * feel free to use string functions like strcmp, strcat, etc 
 * to make this one work
 * myPrint returns 0 on failure and 1 on success
 */
int myPrint(const char *str)
{
	/* Problem 2 – implement myPrint using write */ 
	if(write(1,str,strlen(str)) == -1)
	{
		return 0;
	}

	return 1;
}

/* the myPrintInt function takes a constant int
 * and outputs it to STDOUT using write
 * feel free to use string functions like strcmp, strcat, etc 
 * to make this one work
 * myPrintInt returns 0 on failure and 1 on success
 * Note: you will need to convert the int to a c-string
 * to make it readable
 */
int myPrintInt(const int val)
{
	/* Problem 3 – Implement myPrintInt, you can use write or another existing function you have already defined */ 
	char buf[256];
	sprintf(buf,"%d",val);
	if(write(1,buf,strlen(buf)) ==-1)
	{
		return 0;
	}
	return 1;
}

/* implement the signal hadler below ...
 * use the provided prototype
 * It must handle two signals, SIGINT and SIGALRM
 * if the signal handler receives SIGINT
 * prompt the user if they want to exit or not
 * on yes, exit successfully, on no, just return from the handler
 * on SIGALRM, set the timedout flag to 1
 */
void signalHandler(int sig)
{
	/* Problem 4 – implement the signalHandler .. 
	 * when writing the prompt for SIGINT and reading the reply
	 * use system calls … please also remember to read more than 1
	 * character when reading the response since that response has at least
	 * two characters in it. Yes the responses of ‘Y’ and ‘n’ involve multiple 
	 * characters
	 */
	char arr[10];
	char *ptr = arr;
	if(sig == 2)
	{
		write(1,"\nAre sure to exit y/n : ? ",22);
		while(read(0,ptr,1))
		{
			if(*ptr=='\n')
			{
				*ptr = '\0';
				break;
			}
			ptr++;
		}
		if((strcmp("y",arr)==0))
		{
			exit(0);
		}
		else if((strcmp("n",arr)==0))
		{
			return;
			
		}

	}

	else if(sig == 14)
	{
			
		timed = 1;
	}
}
/* This function reads a line of text from a file
 * we are simulating another functions behavior here ..
 * the basic idea is to read the file character by character til we find
 * the \n or \r
 * Go ahead and tack the null character on here for simplicity
 * Return a 0 if no characters were read, return a 1 otherwise
 */
int readLine(int fd, char *line)
{
	/* Problem 5 – implement readLine as described about ... again
	 * remember to use read to do this …. This is probably best accomplished by
	 * reading in 1 character at a time and then adding them to the array
	 * you passed in as line
	 */
	char ch;
	while(read(fd,&ch,1))
	{
		if(ch == '\n')
		{
			*line = '\0';
			return 1;
		}
		
		*line = ch;
		line++;
	}

	return 0;

}



/* This function reads a question answer pairing
 * from the provided pair of file descriptors
 * It returns 0 if the files are empty
 * and 1 if if successfully reads the pairing
 * notice it calls the custom function readLine since we
 * need to read only one line at a time
 */

int readQA(int questFd, int ansFd, char *quest, char *ans)
{
	if (readLine(questFd,quest) == 0) return 0; 
	if (readLine(ansFd, ans) == 0) return 0;
	return 1;
}

int main(int argc, char *argv[])
{

	int numRead = 0;
	int numWrite = 0;
	int question = 1;
	int correct = 0;
	char buf[BUF_SIZE];
	char quest[BUF_SIZE];
	char ans[BUF_SIZE];
	int questFd, ansFd;


	/* declare structures for signals and timers. 
	 * you will have only one timer, but it has two 
	 * sets of values … one at 30 seconds and one at
	 * 0 seconds
	 */

	/* Problem 6a– declare the structures for the signals and timers */
	
	struct itimerval value1,value2;
	struct sigaction action;

	/* initialize structures for signals and timers 
	 * make certain to actually set a mask this time 
	 * add both SIGINT and SIGALRM to the mask 
	 */

	/* Problem 6b – initialize the structure for the signal handlers */
	action.sa_handler = signalHandler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGALRM,&action,NULL);
	
       

	/* you get 30 seconds a question ... 
	 * this time has no interval, just a value 
	 */

	/* you get 30 seconds a question ... 
	 * this time has no interval, just a value 
	 */

	/* Problem 6c – initialize the structure for the 30 sec timer */
	value1.it_value.tv_sec = 30;
	value1.it_value.tv_usec = 0;
	value1.it_interval.tv_sec=0;
	value1.it_interval.tv_usec=0;


	/* you also need to disable the timer when testing
	 * this is done by setting interval and value to 0
	 */

	/* Problem 6d – initialize the structure for the 0 sec timer*/ 
	value2.it_value.tv_sec = 0;
	value2.it_value.tv_usec = 0;
	value2.it_interval.tv_sec = 0;
	value2.it_interval.tv_usec = 0;
	

	/* set up the signal handlers */

	/* Problem 7 – associate the SIGINT and SIGALRM with their signal handler */
	signal(SIGINT,signalHandler);
	
	/* open the question and answer files .. these are simple text files 
	 * called quest.txt and ans.txt. 
	 */

	/* Problem 8 – open the files quest.txt and ans.txt */
	questFd = open("quest.txt",O_RDONLY);
	if(questFd == -1)
	{
		printf("Error while opening quest.txt file...\n");
		exit(0);
	}
	ansFd   = open("ans.txt",O_RDONLY);
	if(ansFd == -1)
	{
		printf("Error while opening ans.txt file...\n");
		exit(0);
	}


	/* this loop handles the Q/A stuff 
	 * I have included some of it to make you life simpler 
	 * I have also left some commnents to assist you as well 
	 *
	 * read the first question, answer pairing prior to entering the loop
	 */
	readQA(questFd, ansFd, quest, ans);
	while (1)
	{
		/* output the current question */
		myPrint("#");
		myPrintInt(question);
		myPrint(" ");
		myPrint(quest);
		myPrint("? ");
		/* we will set the timedout flag to 0, since it hasn't yet */
		timed = 0;

		/* now set the interval timer prior to reading in the user's response */

		/*  Problem 9 – set the interval timer to go off in 30 seconds */
		setitimer(ITIMER_REAL,&value1, NULL);
	

		/* read in the user's response, this is systems programming so don't use 
		 * scanf */
		
		/* Problem 10 – read a buffer from STDIN */
		numRead = read(0,buf,BUF_SIZE);
	

		/* test to see if the user responded and if an error has occurred 
		 * an error can actually occur as part of the functionality of this program 
		 * both SIGINT and SIGALRM will cause the read call to return a -1 
		 * this can be recognized by testing for a specific error number ...  
		 * The error is known as interrupted systems call 
		 * Should this be the case, do the following .... 
		 * If the read call was interrupted and the timedout flag isn't set 
		 * just continue 
		 * if the timedout flag was set, inform the user that time is up 
		 * then go to the next question
		 */
		if (numRead == 0) break;
		if (numRead == -1)
		{
			if (errno == EINTR)
			{
				if (timed)
				{
					myPrint("\nTime's up, next question\n");
					if (readQA(questFd, ansFd, quest, ans) == 0) break;
					question++;
				}
				continue;
			}
			perror("read");
			exit(EXIT_FAILURE);
		}
		/* disable the timer here ...
		 * we are doing stuff that takes time
		 * you can disable the timer by passing
		 * do this by calling the interval time with a value and interval of 0 
		 */
		/* Problem 11 – disable the time by setting it to tvOff */
		setitimer(ITIMER_REAL,&value2,NULL);

		/* we will convert the buf being read in to a c-string by tacking on a 0 */
		buf[numRead-1] = 0;
		/* check the answer */
		if (strcmp(buf,ans) == 0)
		{
			correct++;
			myPrint("\ncorrect\n");
		} else
		{
			myPrint(ans);
			myPrint("\nwrong\n");
		}
		/* read the next question .. break if there are no more questions */
		if (readQA(questFd, ansFd, quest, ans) == 0) break;

		question++;
	}

	myPrint("final score is ");
	myPrintInt(correct);
	myPrint(" out of ");
	myPrintInt(question);
	printf("\n");

	/* Problem 12 – close both files */
	close(questFd);
	close(ansFd);

}