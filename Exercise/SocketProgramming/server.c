#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void error(char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char **argv)
{
	int sockfd, newsockfd, portno, clilen, n;
	char buff[256];
	struct sockaddr_in serv_addr, cli_addr;

	char str[100];
	char dob1[9], dob2[9];
	char code[10], code1[10];
	char result[2];

	int k;
	FILE *fptr;

	printf("Enter server port number: ");
	scanf("%d",&portno);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
		error("ERROR opening socket");

	bzero((char *)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR on binding");

	while(1)
	{
		listen(sockfd, 5);
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if(newsockfd < 0)
			error("ERROR on accept");

		printf("Client connected...\n");
		bzero(buff, 256);

		n = read(newsockfd, buff, 255);
		if(n < 0)
			error("ERROR reading from socket");

		sscanf(buff, "%s",code1);
		code[9] = 0;

		sscanf(buff, "%s",dob2);
		dob2[8] = 0;

		fptr = fopen("testResult20.txt","r");

		while(fgets(str, 100, fptr))
		{
			sscanf(str, "%s",code);
			code[9] = 0;

			if(strcmp(code, code1) != 0)
				continue;

			sscanf(str+10, "%s",dob1);
			dob1[8] = 0;

			if(strcmp(dob1, dob2) != 0)
				continue;

			k = strlen(code) + strlen(dob1) + 1;
			sscanf(str+k, "%s",result);
			break;
		}

		if(!result)
			strcpy(result, "X");

		printf("Test Code  : %s\n",code1);
		printf("BirthDate  : %s\n",dob2);
		printf("Test Result: %c\n",result[0]);

		fclose(fptr);

		n = write(newsockfd, &result, 1);
		if(n < 0)
			error("ERROR writing to socket");

		bzero(result, 2);
	}

	return 0;
}
