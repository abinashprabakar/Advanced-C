
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5};
 	printf("arr [0] is %d\n",arr[0]);
 	printf("arr[10] is %d\n",arr[10]);

	arr[10] = 11;	/* array out of bound */
 	printf("arr[10] is %d\n",arr[10]);	/* accessing the memory which is not allocated */
	return 0;

}
