/* input : 1		---> no. of rows to be printed
 * 	   5 2 		
 * 	   1 2 3 4 5 	---> elements
 *
 * output : 4 5 1 2 3
 */

#include<stdio.h>

int main()
{
	int a[50];
	int num, n, i, k;
	scanf("%d",&num);
	while(num--)	/* Number of rows */
	{
		scanf("%d %d",&n,&k);
	    while (k >= n) k -= n;
		for(i=0; i<n; i++)	/* storing n elements */
		{
			scanf("%d",&a[i]);
		}
		/* i=5-2=> 3<5 a[3]=4
		   i=4    4<5  a[4]=5
		   i=5    5<5 condition failed
	    */
		for(i = n-k; i < n; i++)	
		{
			printf("%d ",a[i]);
		}
		/* i=0   i<5-2 true a[0]=1
		   i=1   i<5-2 true a[1]=2
		   i=2   i<5-2 true a[2]=3
		   i=3   i<5-2 condition failed
		*/
		for(i=0; i < n-k; i++)
		{
			printf("%d ",a[i]);	/* 4 5 1 2 3 */
		}
		printf("\n");
	}
	return 0;
}
