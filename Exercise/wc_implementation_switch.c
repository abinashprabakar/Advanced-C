#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

/* prints Usage information when wrong command is passed */
void usage(char *a)
{
	fprintf(stderr, "Usage: %s [-lcw] <filename>\n",a);
	exit(EXIT_FAILURE);
}

/* main program */
int main(int argc, char **argv)
{
	int cflag = 0;	/* holds status of c flag */
	int lflag = 0;	/* holds status of l flag */
	int wflag = 0;	/* holds status of w flag */
	char fname[256], linestr[256];	/* holds filename and line string */
	int parameter;	/* parameter count */

	FILE *fp = NULL;

	int lcnt = 0;	/* line count */
	int wcnt = 0;	/* word count */
	int ccnt = 0;	/* character count */

	int len, state = 0;
	char *str;	/* string pointer */
	char ch;

	while((ch = getopt(argc, argv, "wlc")) != -1)	/* getopt -> get option information */
	{
		switch(ch)
		{
			case 'c':			/* if option c passed */
			{
				cflag = 1;		/* cflag set */
			}

			case 'l':			/* if option l passed */
			{
				lflag = 1;		/* lflag set */
			}

			case 'w':			/* if option w passed */
			{
				wflag = 1;		/* wflag set */
			}

			break;
			case '?':			/* when new arguments is passed */
			{
				usage(argv[0]);		/* passing usage function */
			}
			break;
		}
	}

	parameter = argc - optind;			/* checking if the parameter is present after all options */

	if(wflag == 0 && lflag == 0 && cflag == 0)	/* count word by default */
		wflag = 1;

	if(parameter == 0)				
		fp = stdin;
	else
	{
		fp = fopen(argv[optind], "r");		/* open file as per your option */
		if(fp == NULL)
		{
			printf("Error : File does not exist \n");
			exit(EXIT_FAILURE);
		}
	}

	while(fgets(linestr, sizeof(linestr), fp) != NULL)	/* read the file upto end of the line in loop */
	{
		len = strlen(linestr);			/* find the length of line */
		if(linestr[len-1] == '\n')		/* check if \n is present at end */
			lcnt++;				/* increment if found */
		ccnt = ccnt+len;			/* incrementing character count with length */
		str = linestr;				/* store string buffer to str */

		while(*str)
		{
			if(*str == ' ' || *str == '\n' || *str == '\t')	/* if special character is found */
				state = 0;
			else if(state == 0)
			{
				state = 1;
				wcnt++;
			}
			++str;
		}
	}

	if(lflag)
		printf(" %d",lcnt);	/* display line count */

	if(wflag)
		printf(" %d",wcnt);	/*display word count */

	if(cflag)
		printf(" %d",ccnt);	/* display character count */

	printf(" %s",argv[optind]);	/* display the filename */
	
	printf("\n");
	fclose(fp);
	return 0;
}
