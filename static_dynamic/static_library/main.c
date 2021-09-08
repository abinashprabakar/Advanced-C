/* This program implements the working of static library
 *
 * Email : abinashprabakaran@gmail.com
 * Date : 08.09.2021
 * Author : Abinash
 */

#include<stdio.h>	/* required for printf */

/* main program */
int main()
{
	int result;
	print("Hello");	/* print function call */

	result = sum(10, 20);	/*sum function call */
	printf("Sum : %d\n",result);

	result = multiplication(10, 3);		/* multiplication function call */
	printf("Multiplication : %d\n",result);

	return 0;
}
