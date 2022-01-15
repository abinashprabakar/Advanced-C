#include<stdio.h>

int main()
{
	int n;

	printf("Enter the number : \n");
	scanf("%d",&n);

	if(n & (1 << (sizeof(n) * 8 - 1)))
		printf("%d is Negative \n",n);

	else
		printf("%d is Positive \n",n);

	return 0;
}
