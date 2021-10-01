/* Write a program called setupClass; this program creates a directory structure for all of your files associated with
 * the exercises, assignments, and tests.
 *
 * The setupClass program has one optional command line argument which represents the name of the root directory to
 * setup; if the argument is omitted then the root directory should default to "sysProg".
 *
 * The directory structure should be constructed as follows:
 *
 * 							<root>
 *
 * 	test 				program						 exercise
 *
 * test1 test2 test3 	prog1 prog2 prog3 prog4 progS 	exer1 exer2 exer3 exer4 exer5 exer6 exer7 exer8 exer9 exer10
 * 	
 * 	Use loops and system calls to construct this directory structure.
 *
 * 	You should consider using the mkdir, chdir, getcwd calls to make this structure efficiently.
 *
 * Email : abinashprabakaran@gmail.com
 * Date : Abinash
 * Author : Abinash
 */

/* headers required for printf, mkdir, chdir, stat, access */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>

/* creating a directory */
void create(char *dir, mode_t mode)
{
	char path[100], *p;
	size_t len;	/* size of len */

	strncpy(path, dir, sizeof(path));
	path[sizeof(path) - 1] = '\0';	/* Last character as NULL character */
	len = strlen(path);		/* length of path */
	
	if(len == 0)
		return;
	else if(path[len-1] == '/')
		path[len-1] = '\0';
	for(p = path; *p; p++)		/* creating a directory or sub-directory */
		if(*p == '/')
		{
			*p = '\0';
			if(access(path, F_OK))
				mkdir(path, mode);
			*p = '/';
		}
	if(access(path, F_OK))		/* create a directory when it has a access */
		mkdir(path, mode);
}

/* main program */
int main(int argc, char **argv)
{
	char root[100] = "sysProg", buf[100];
	struct stat s;			/* directory file structure */
	int count;

	if(argc > 1)
		strcpy(root, argv[1]);	/* copying argv[1] to root */

	if(stat(root, &s) == 0)		/* if structure already exists */
	{
		printf("Already exists\n");
		exit(EXIT_FAILURE);
	}

	create(root, 0755);	/* creating root directory */
	chdir(root);		/* entering the root directory */
	
	mkdir("test",0755);	/* creating test directory */
	for(count = 0; count < 3; count++)
	{
		sprintf(buf, "test/test%d",count+1);	/* creating 3 test sub directories */
		create(buf, 0755);
	}

	mkdir("exercise",0755);	/* creating exercise directory */
	for(count=0; count < 5; count++)
	{
		sprintf(buf, "exercise/exer%d",count+1); /* creating 5 exer sub directories */
		create(buf, 0755);
	}

	mkdir("program",0755);	/* creating program directory */
	for(count=0; count<10;count++)
	{
		sprintf(buf, "program/prog%d",count+1);	 /* creating 10 prog sub directories */
		create(buf, 0755);
	}

	return 0;
}
