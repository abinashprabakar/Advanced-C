/* This program implements the operation of dynamic library
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
	print("Hello");

	result = sum(10, 20);	/* sum function call */	
	printf("Sum : %d\n",result);

	result = mul(10, 30);	/* multiplication function call */
	printf("Multiplication : %d\n",result);

	return 0;
}
