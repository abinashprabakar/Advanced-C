/*
You know that C strings end with a '\0' character, without which string operations would be impossible
 because they would not know where to stop processing. But this is not the only way to store strings.

Dan proposes to store strings in character arrays as follows:

- The first character n is interpreted as an integer giving the number of characters that constitute the string
The next n characters are the actual contents of the string

For example, to represent the string
dan
we'd use an array of four characters: 3, 'd', 'a', 'n'. (Remember that a character is just a small int.)

These are called Dan strings.

Write the following function that takes a character array representing a Dan string, and allocates and
returns a proper null-terminated C string. s is NOT to be modified.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *dan_to_c(const char *s) 
{
	/* allocating memory for the char p */
	char *p = (char *)malloc(strlen(s));
	strcpy(p,s+1);	/* copying contents from s to p */
	return p;
}


/*
Write the following function that takes two arrays representing Dan strings and
concatenates the second to the first. s1 is to be modified.

Assume the array s1 is always large enough.
*/

void dan_strcat(char *s1, const char *s2) 
{
	strcat(s1, s2+1);	/* concatenating the s2(avoiding the starting integer) to s1 */
	int s = strlen(s1) - 1;
	int i=1;
	/* if the first value is more than 9 */
	if(s > 9)
	{
		memmove(s1+1, s1, strlen(s1));
		while(s!=0)
		{
			s1[i] = 48 + (s % 10);
			s = s / 10;	/* s1[0] = 1  s2[0] = 5 */
			i--;
		}
	}
	/* if the first value is less than 9 */
	else
	{
		s1[0] = s1[0] + strlen(s2)-1;
	}
}

int main()
{
	char s1[20] = "3dan";
        const char s2[] = "3dan";
	printf("s1 = %s\ns2 = %s\n",s1,s2);
	char *a = dan_to_c(s2);
	dan_strcat(s1,s2);
	printf("%s\n",s1);
}

