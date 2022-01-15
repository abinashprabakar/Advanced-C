/* This C program finds the median of the array values got from the user and sort the first half in ascending order 
 * and second half in descending order
 *
 * Example : array = 1 2 3 4 5
 * median = 2
 * 1 2    3 4 5
 *
 * 1 2   5 4 3
 * 
 * output = 1 2 5 4 3
 *
 * Email : abinashprabakaran@gmail.com
 * Author : Abinash
 * Date : 06.01.2022
 */

#include<stdio.h>	/* required for printf, scanf */
#include<stdlib.h>	/* required for malloc */

int main()
{
	int n,i,j,temp;

	printf("Enter the size of array : ");	/* get the size from user */
	scanf("%d",&n);

	int *a = (int *)malloc(sizeof(int));	/* dynamic memory allocation */
	
	printf("Enter the %d elements : ",n);	/* get the n number of elements */
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("Median : %d\n",n/2);		/* print median of the given numbers */

	for(i=0;i<n-1;i++)			/* check i is less than the total size */
	{
		for(j=0;j<n/2;j++)		/* sorting first half in ascending order */
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		
		for(j=n/2;j<n-1;j++)		/* sorting second half in descending order */
		{
			if(a[j] < a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	printf("After sorting : \n");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);		/* printing the sorted result */

	printf("\n");

	return 0;
}
