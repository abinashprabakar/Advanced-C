#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, temp=1, result=0;
    
    	printf("Enter two numbers \n");
        scanf("%d %d",&a,&b);
    
    	while(b <= a) 
	{
		b<<=1;
		temp<<=1;
	}

	while(temp>1)
	{
    		b>>=1;
		temp>>=1;

		if(a >= b)
		{
    			a -= b;
     			result += temp;
		}
	}

	printf("a / b : %d\n",result);
    
	return 0;
}
