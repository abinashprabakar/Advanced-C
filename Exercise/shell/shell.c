/* Implementation of shell command in c 
 * Email : abinashprabakaran@gmail.com
 * Date : 10.10.2021
 * Author : Abinash 
 */

#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

/* Function Declarations for builtin shell commands: */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

/* List of builtin commands, followed by their corresponding functions. */
char *builtin_str[] = {"cd", "help", "exit"};

/* array of pointers to function returning int and taking pointer to pointer to char as argument */
int (*builtin_func[]) (char **) = { &lsh_cd, &lsh_help, &lsh_exit};

/* finding the size of builtin_str */
int lsh_num_builtins() 
{
	return sizeof(builtin_str) / sizeof(char *);
}

/* Builtin function implementations. */
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "sh: expected argument to \"cd\"\n");
	} 
	
	else 
	{
		if (chdir(args[1]) != 0) 
		{
			perror("sh");
		}
	}
  	
	return 1;
}


int lsh_help(char **args)
{
	int i;
  //	printf("Type program names and arguments, and hit enter.\n");
  	printf("The following are built in:\n");

  	for (i = 0; i < lsh_num_builtins(); i++) 
	{
		printf("  %s\n", builtin_str[i]);
  	}

  	printf("Use the man command for information outside the program \n");
  	return 1;
}

int lsh_exit(char **args)
{
	return 0;
}

int lsh_launch(char **args)
{
	pid_t pid;
  	int status;

  	pid = fork();	/* fork system call */
  	if (pid == 0) 
	{
    		/* Child process */
    		if (execvp(args[0], args) == -1) 
		{
			perror("sh");
    		}
    		exit(EXIT_FAILURE);
  	} 
	
	else if (pid < 0) 
	{
		/* Error forking */
		perror("lsh");
  	} 
	
	else 
	{
		/* Parent process */
		do 
		{
			/* return if child has stopped */
			waitpid(pid, &status, WUNTRACED);
		}while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;	/* returns true */
}

int lsh_execute(char **args)
{
	int i;

  	if (args[0] == NULL) 
	{
    		/* An empty command was entered. */
		return 1;
  	}

  	for (i = 0; i < lsh_num_builtins(); i++) 
	{
    		if (strcmp(args[0], builtin_str[i]) == 0) 
		{
			return (*builtin_func[i])(args);
    		}
  	}

  	return lsh_launch(args);
}

char *lsh_read_line(void)
{
	
	#ifdef LSH_USE_STD_GETLINE
  	char *line = NULL;
  	ssize_t bufsize = 0; /* have getline allocate a buffer for us */
  	if (getline(&line, &bufsize, stdin) == -1) 
	{
		if (feof(stdin)) 
		{
			exit(EXIT_SUCCESS);  /* We received an EOF */
		}
		
		else  
		{
			perror("sh: getline\n");
      			exit(EXIT_FAILURE);
    		}
  	}
 	return line;
	
	#else
	#define LSH_RL_BUFSIZE 1024
  
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
  	char *buffer = malloc(sizeof(char) * bufsize);	/* allocating dynamic memory for buffer */
  	int c;

  	if (!buffer) 
	{
		fprintf(stderr, "sh: allocation error\n");
    		exit(EXIT_FAILURE);
  	}

  	while (1) 
	{
		/* Read a character */
		c = getchar();

    		if (c == EOF)	/* if character reached end of the file */ 
		{
			exit(EXIT_SUCCESS);
    		} 
		
		else if (c == '\n') 
		{
			buffer[position] = '\0';
      			return buffer;
    		} 
		
		else 
		{
      			buffer[position] = c;
    		}
   		position++;

    		/* If we have exceeded the buffer, reallocate. */
    
		if (position >= bufsize) 
		{
			bufsize += LSH_RL_BUFSIZE;
      			buffer = realloc(buffer, bufsize);	/* reallocating when position > buffer */
      			if (!buffer) 
			{
				fprintf(stderr, "sh: allocation error\n");
        			exit(EXIT_FAILURE);
      			}
    		}
  	}
	#endif
} 

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
  	char **tokens = malloc(bufsize * sizeof(char*));	/* allocating dynamic memory for token */
  	char *token, **tokens_backup;

  	if (!tokens) 
	{
		fprintf(stderr, "sh: allocation error\n");
    		exit(EXIT_FAILURE);
  	}

  	token = strtok(line, LSH_TOK_DELIM);
  	
	while (token != NULL) 
	{
    		tokens[position] = token;
    		position++;

    		if (position >= bufsize) 
		{
      			bufsize += LSH_TOK_BUFSIZE;
      			tokens_backup = tokens;
      			tokens = realloc(tokens, bufsize * sizeof(char*));/* reallocating memory when pos > buf */
      
			if (!tokens) 
			{
				free(tokens_backup);
        			fprintf(stderr, "sh: allocation error\n");
        			exit(EXIT_FAILURE);
      			}
    		}

    		token = strtok(NULL, LSH_TOK_DELIM);
  	}
  	tokens[position] = NULL;
  	return tokens;
}

void lsh_loop(void)
{
	char *line;
  	char **args;
  	int status;

  	do 
	{
		printf("$ ");
    		line = lsh_read_line();
    		args = lsh_split_line(line);
    		status = lsh_execute(args);

    		free(line);
    		free(args);
  	}while (status);
}

int main(int argc, char **argv)
{
	/* Load config files, if any. */

  	/* Run command loop. */
  	lsh_loop();

  	/* Perform any shutdown/cleanup. */

  	return EXIT_SUCCESS;
}
