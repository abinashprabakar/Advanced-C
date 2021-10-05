#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
	int character_count = 0, word_count = 0, line_count = 0;
	char ch;

        FILE *fp;

        if(argc == 0)
	{
		printf("Please specify the filename as argument\n");
                exit(0);
        }

        if(fp != 0)
        {
		printf("No such file or directory\n");
		exit(0);
        }
        
     	fp = fopen(argv[1],"r");

        while((ch=fgetc(fp))!=EOF)
        {
		character_count++;
                if(ch == ' ')
                {
                        word_count++;
                }
		
		if(ch == '\n')
                {
			line_count++;
                }
	}
        
	printf(" %d %d %d %s\n",character_count,word_count,line_count,argv[1]);

	return 0;

}
