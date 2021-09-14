/* input : 2   --> total matrix	 	output : 0 ---> 0 when every first element less than second element
 * 	   3   --> 3x3 matrix			 2 ---> non-zero when first element greater than second element
 * 	   1 2 3 
 * 	   4 5 6 
 * 	   7 8 9
 * 	   
 * 	   2   --> 2x2 matrix
 * 	   4 3 
 * 	   1 4
 */

#include<stdio.h>

int main()
{
	int m[20][20];
	int c, n, t, i, j, k, count=0, x, y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		count = 0;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf("%d",&m[i][j]);
			}
		}

		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				for(x = i; x < n; x++)
				{
					for(y = j; y < n; y++)
					{
						/* comparing the elements between rows
						 * and elements
						 */
						if(m[x][y] < m[i][j])
							count++;
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
