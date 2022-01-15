#include<stdio.h>

int main()
{
	int a, b ,count = 0, result = 0;
	
	printf("Enter two numbers to perform multiplication : ");
	scanf("%d %d",&a,&b);

	while(b)
	{
		if(b % 2 == 1)
			result += a << count;

		count++;
		b/=2;
	}

	printf("a * b = %d\n",result);

	return 0;
}
