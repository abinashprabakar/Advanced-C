#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 * You know that C strings end with a '\0' character, without which string operations would be impossible
 *  because they would not know where to stop processing. But this is not the only way to store strings.
 *
 *  Dan proposes to store strings in character arrays as follows:
 *
 *  - The first character n is interpreted as an integer giving the number of characters that constitute the string
 *  The next n characters are the actual contents of the string
 *
 *  For example, to represent the string
 *  dan
 *  we'd use an array of four characters: 3, 'd', 'a', 'n'. (Remember that a character is just a small int.)
 *
 *  These are called Dan strings.
 *
 *  Write the following function that takes a character array representing a Dan string, and allocates and
 *  returns a proper null-terminated C string. s is NOT to be modified.
 *  */

char *dan_to_c(const char *s)
{
	char *ptr = (char *)malloc(s[0]+1);
	int i;
	for(i=1;i<s[0]+1;i++)
	{
		ptr[i-1] = s[i];
	}
	ptr[i] = '\0';
	return ptr;
}

/*
 * Write the following function that takes two arrays representing Dan strings and
 * concatenates the second to the first. s1 is to be modified.
 *
 * Assume the array s1 is always large enough.
 * */



void dan_strcatt(char *s1, const char *s2)
{

	int i,n= s1[0];
	for(i=1;i<s2[0]+1;i++)
	{
		s1[i+n] = s2[i];
	}
	s1[0] = i-1+s1[0];

}


void print(char *ptr,int n)
{
	int i;
	for(i=1;i<n+1;i++)
	{
		printf("%c",ptr[i]);
	}
	printf("\n");
}

int main()
{
	
	char d_arr[20] = {7,'A','b','i','n','a','s','h'};
	const char dan[] = {8,'P','r','a','b','a','k','a','r'};
	char *a = dan_to_c(dan);
	printf("a: %s\n",a);
	dan_strcatt(d_arr,dan);
	print(d_arr,d_arr[0]);
	print(dan,dan[0]);	

	return 0; 
}
