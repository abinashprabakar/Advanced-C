#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, op;
   	int key = 4;
   	char str[100],ch;

   	printf("Please enter a string:\t");
   	scanf("%[^\n]s",str);

   	printf("Select the operation need to be performed\n");
   	printf("1. Encryption\n");
   	printf("2. Decryption\n");
	printf("3. Exit\n");
   	scanf("%d", &op);

	switch(op)
   	{
   		case 1:
			for(i = 0; (i < 100 && str[i] != '\0'); i++)
				str[i] = str[i] + key; 
		
			printf("Encrypted string: %s\n", str);
      			break;

   		case 2:
      			for(i = 0; (i < 100 && str[i] != '\0'); i++)
        			str[i] = str[i] - key; 
      
      			printf("\nDecrypted string: %s\n", str);
      			break;

		case 3:
			exit(0);
   			
		default:
			printf("Enter the correct option\n");
	}
   
	return 0;
}
