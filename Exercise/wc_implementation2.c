#include <stdio.h>
#include <string.h>


/*Finding Number of new line characters in a buffer*/
int find_count_of_lines(const char *str)
{
        int liness=0, i=0;
        for(i=0; str[i] != '\0'; i++)
	{
                if( str[i] == '\n' )	/* count when a new line is found */
		{
                        liness+=1;
                }
        }
        return liness;
}

int find_count_of_words(const char *str)
{
        int words=0, i;
        // skip initial white space characters
        while(str[i] != '\0')
	{
                if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t')
		{
                        i++;
                }
		else
		{
                        break;
                }
        }
        for(i=0 ; str[i] != '\0'; i++)
	{
                if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t' )
		{
                        words+=1;
                        // skip consucative white space
                        while(str[i]==' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t')
			{
                                i++;
                        }
                }
        }
        return words;
}

/* count no of characters */
int txt_my_wc(FILE *fp, int *lines_p, int *words_p, int *chars_p)
{
        int  lines=0, words=0, chars=0;
        char buffer[100];
        size_t bytes;
        fseek(fp, 0, SEEK_SET);
        do
	{
                memset(buffer, 0, sizeof(buffer));
                bytes = fread(buffer, sizeof(char), sizeof(buffer)-1, fp);
                if(bytes > 0)
		{
                        lines += find_count_of_lines(buffer);
                        words += find_count_of_words(buffer);
                        chars += bytes;
                }
        }while(bytes > 0);
        *lines_p = lines;
        *words_p = words;
        *chars_p = chars;
        return chars;
}


int main(int argc, char *argv[])
{
        FILE *fp = NULL;
        int lines=0, words=0, chars=0;
        if(argc != 2)
	{
                fprintf(stderr, "USAGE: %s <filename> \n", argv[0]);
                return -1;
        }
        fp = fopen(argv[1], "r");

	txt_my_wc(fp, &lines, &words, &chars);
       	printf("  %d  %d  %d  %s\n", lines, words, chars, argv[1]);
        fclose(fp);
        return 0;
}	
