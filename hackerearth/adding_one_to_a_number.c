/* input : 2   ---> no. of rows
 * 	   456
 * 	   123
 *
 * output :
 * 	   457
 * 	   124
 */

#include<stdio.h>

int main()
{
	int n,t;
	scanf("%d",&t);	/* no. of rows */
	while(t--)
	{
		scanf("%d",&n);	
		printf("%d\n",n+1);
	}
	return 0;
}
