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
 */
#include<stdio.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

void test()
{
	system("mkdir test1 test2 test3");
	chdir("..");
}

void exercise()
{
	system("mkdir exer1 exer2 exer3 exer4 exer5 exer6 exer7 exer8 exer9 exer10");
	chdir("..");
}

void program()
{
	system("mkdir prog1 prog2 prog3 prog4 prog5");
	chdir("..");
}

int main(int argc, char **argv)
{
	char cwd[100];
	if(argc != 2)
	{
		printf("Usage : ./setupClass sysProg\n");
		return 0;
	}

	mkdir(argv[1],0777);
	chdir(argv[1]);
	
	mkdir("test",0777);
	chdir("test");
	test();

	mkdir("exercise",0777);
	chdir("exercise");
	exercise();

	mkdir("program",0777);
	chdir("program");
	program();

	if(getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n",cwd);

	return 0;
}


