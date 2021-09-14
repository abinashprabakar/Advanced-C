

#include<stdio.h>
int a,b,c=10;			/* global variables */
static int x,y=10,z=20;         /* global static variables */
int main()
{
	int i,j=5;              /* local variables */
	static int i,j,k,n,m;   /* local static variables */
	printf("hello \n");
	return 0;
}
