#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

/* main program */
int main()
{
	FILE *fp;
	int r, num, i;
	srand(time(0));			/* To generate random number for every execution */
	r = rand() % 256;		/* Generating random number between 0 to 255 */

	char fname[256];
	sprintf(fname, "data%d.dat",r);	/* concatenating the generated number with the filename */

	fp = fopen(fname, "w");		/* opening file in write mode */	
	if(fp == NULL)
	{
		printf("Error : File does not exist \n");
		exit(0);
	}

	for(i=0; i<60; i++)		/* generating 60 numbers between 0 to 100 */
	{
		num = rand() % 101;
		fprintf(fp, "%d ",num);	/* storing the 60 numbers in the data.dat file */
	}

	fclose(fp);			/* close the file */

	printf("Generated number : %d\n",r);
	exit(r);			/* exit with status r */
}
