#include<stdio.h>	/* required for printf, scanf */
#include<sys/types.h>
#include<sys/socket.h>	/* required for socket types */
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void error(char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char **argv)
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char host[20], buffer[256];

	printf("Enter the host name: ");
	scanf("%s",host);
	host[strlen(host)] = 0;
	printf("Enter port no: ");
	scanf("%d",&portno);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		error("ERROR opening socket");

	server = gethostbyname(host);
	if(server == NULL)
	{
		fprintf(stderr, "ERROR, no such host");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port = htons(portno);

	if(connect(sockfd,&serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	bzero(buffer, 255);
	
	printf("Please enter the 9 digit code and DOB(DD/MM/YYYY): ");
	fflush(stdout);
	read(0, buffer, 255);

	n = read(sockfd, buffer, 255);
	if(n < 0)
		error("ERROR reading from socket");

	if(buffer[0] == 'P')
		printf("Your test result is POSITIVE. \n");

	else if(buffer[0] == 'N')
		printf("Your test result is NEGATIVE. \n");

	else
		printf("The test result you requested is not in our database. \n");

	return 0;
}
