#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int *a = (int *)malloc(sizeof(int));

	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}

	printf("\n");

	return 0;
}
