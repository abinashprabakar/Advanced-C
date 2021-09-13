/* input : 2   ---> no of m[i][j]
 *         3   ---> no of rows and columns eg: 3x3
 *         1 2 3 
 *         4 5 6 
 *         7 8 9
 *
 *         2   ---> no of rows and columns eg: 2x2
 *         4 3 
 *         1 4
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
						if(m[x][y] < m[i][j]) /* comparing the values between rows & columns */
							count++;
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
