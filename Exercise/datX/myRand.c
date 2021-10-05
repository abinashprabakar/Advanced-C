#include<stdio.h>	/* required for printf, scanf */
#include<stdlib.h>	/* required for asprintf */
#include<unistd.h>
#include<string.h>	/* required for string operations */

/* main program */
int main()
{
	FILE *fp;
	int num, i, no;
	char *fname, *n;

	num = rand() % 255;	/* random number between 0 to 255 */
	fname = (char *)malloc(sizeof(char));	/* allocating memory for fname */

	strcpy(fname, "data.dat");		/* copying data.dat to fname */

	if(asprintf(&n, "%d",num) == -1)
	{
		printf("Error: Can't convert to string\n");
		exit(0);
	}

	memmove(fname+strlen(fname)-1, fname+4, 5);	/* moving .dat to data */
	memmove(fname+4, n, 3);

	fp = fopen(fname, "w");			/* opening file in write mode */
	if(fp == NULL)
	{
		printf("Error: No file or directory created\n");
		exit(0);
	}

	for(i=0; i<60; i++)			/* generate 60 random numbers between 0 to 100 */
	{
		no = rand() % 100;
		fprintf(fp, "%d ",no);
	}

	fclose(fp);				/* closing the file */
	printf("%d\n",num);

	exit(num);
}
