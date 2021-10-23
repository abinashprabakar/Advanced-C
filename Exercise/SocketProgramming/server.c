/* This is the client program. Client program will connect to the server and request the covid test results 
 * 
 * Email : abinashprabakaran@gmail.com
 * Author : Abinash
 * Date : 20.10.2021
 */

/*! include headers */
#include<stdio.h>		/*! required for printf() scanf() */
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>		/*! required for strlen() bzero */

/*! function to print error message */
void error(char *msg)
{
	 perror(msg);
	  exit(0);
}

/*! main program starts */
int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char host[20];
	char buffer[256];
	/*! reading the host name from the stdin */
	printf("Enter the host name: ");
	scanf("%s",host);
	host[strlen(host)] = 0;
	/*! reading the port number from stdin */
	printf("enter port no: ");
	scanf("%d",&portno);
	/*! creating endpoint for communication */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");

	/*! Given the name of a host, gethostbyname returns a pointer to the hostent structure containing the host's IP address and other information.*/
	server = gethostbyname(host);
	if (server == NULL)
	{
		fprintf(stderr,"ERROR, no such host");
		exit(0);
	}

	/*! bzero() function initializes the structure variable with zeros */
	bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);

	

	if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	/*! initializing buffer with zeros to avoid garbage values */
	bzero(buffer,255);
	/*! promt to the user to enter 9 digit unique code and birthdate */
	printf("Please enter the 9 digit code and DOB(DD/MM/YEAR): ");
	/*! flushing stdout */
	fflush(stdout);
	/*1 reading the user entered data from the stdin */
	read(0,buffer,255);
	/*!sending the data to server */
	n = write(sockfd,buffer,strlen(buffer));
	if (n < 0)
		error("ERROR writing to socket");
	/*! initializing buffer with zeros to avoid garbage values */
	bzero(buffer,255);
	/*1 reading the data from the server */
	n = read(sockfd,buffer,255);
	if (n < 0)
		error("ERROR reading from socket");
	/*! comparing the test results received from server*/
	if(buffer[0] == 'P')
	{
		printf("Your test result was POSITIVE.\n");
	}
	/*! N for nagative */
	else if(buffer[0] == 'N')
	{
		printf("Your test result was NEGATIVE.\n");
	}
	/*! X means not found the test results */
	else if(buffer[0] == 'X')
	{
		printf("The test result you requested is not in our database.\n");
	}

	return 0;
}
