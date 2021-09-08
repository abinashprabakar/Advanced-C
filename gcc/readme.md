**GCC**

		GCC stands for GNU Compiler Collections which is used to compile mainly C and C++ language. 
		It can also be used to compile Objective C and Objective C++. The most important option required 
		while compiling a source code file is the name of the source program, rest every argument is optional 
		like a warning, debugging, linking libraries, object file etc.

		The different stages of gcc command allows the user to stop the compilation process at different stages.
				
			1. Preprocessing stage [ Removal of comments, Expansion of macros, etc,. ] -> filename.i
			2. Compiling stage [ produce intermediate compiled output file ] -> filename.s
			3. Assembly stage [ existing code is converted into machine language ] -> filename.o
			4. Linker stage [all the linking of function are done ] -> filename


**GCC Options**

		When you invoke GCC, it normally does preprocessing, compilation, assembly and linking.  
		The "overall options" allow you to stop this process at an intermediate stage.  For example, the 
		-c option says not to run the linker.  Then the output consists of object files output by 
		the assembler.


				-c  -S  -E  -o file  -x language -v  -###
           			--help[=class[,...]]  --target-help  --version
           			-pass-exit-codes  -pipe  -specs=file  -wrapper @file
           			-ffile-prefix-map=old=new -fplugin=file
           			-fplugin-arg-name=arg -fdump-ada-spec[-slim]
           			-fada-spec-parent=unit  -fdump-go-spec=file

		
**_1. -D name_**
```
		Predefine name as macro, with definition 1.

Eg : 
#include<stdio.h>
int main()
{
	printf("Value : %d",CONST);	/* CONST value is declared in the program */
	return 0;
}		 

Compilation : gcc -o main main.c -DCONST=20    /*  CONST value is declared as 20 during compilation time */

Observation :  If -DCONST is not used, the following error occurs
		error: ‘CONST’ undeclared (first use in this function)   
                   4 |  printf("Value : %d",CONST);   
                     |                      ^~~~~      
               main.c:4:22: note: each undeclared identifier is reported only once for each function it appears in

Output : Value : 20

```

**_2. -include file_**
```
		Process file as if "#include "file"" appeared as the first line of the primary source file.  However, 
		the first directory searched for file is the preprocessor's working directory instead of the directory 
		containing the main source file.  If not found there, it is searched for in the remainder of the 
		"#include "..."" search chain as normal.
Eg :

/* header files are not included */
int main()
{
	printf("Value : %d",CONST);
	return 0;
}

Compilation : gcc -o main main.c -include stdio.h

Observation : If -include is not used, the following error occurs
		main.c: In function ‘main’: 
                main.c:4:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration] 
                    4 |  printf("Value : %d",CONST);    
                      |  ^~~~~~  

Output : Value : 20

```

**_3. -U name_**	
```
		Cancel any previous defintion of name, either built in or provided with a -D option.

Eg :
#include<stdio.h>
int main()
{
	printf("Value is %d ",CONST);
	return 0;
}

Compilation : gcc -o main main.c -D CONST = 20 -U CONST

Observation : Even though CONST is declared as 20, -U option cancels the -D option and throws an error as,
		main.c: In function ‘main’:   
                main.c:4:22: error: ‘CONST’ undeclared (first use in this function)
                    4 |  printf("Value : %d",CONST);      
```

**_4. -r_**
```
		Produce a relocatable object as output. This is also known as partial linking.

Eg :
#include<stdio.h>
int main()
{
	printf("Hello\n");
	return 0;
}

Compilation : gcc -o -r main main.c

Observation : A binary file named main is created.

```

**_5. -Werror_**
```
		Make all warnings into errors.

Eg:
/* No header file included */
int main()
{
	printf("Hello\n");
	return 0;
}

Compilation : gcc -o main main.c -Werror

Observation : Warning messages turned into errors, 
                main.c:5:2: error: implicit declaration of function ‘printf’ [-Werror=implicit-function-declaration]
                    5 |  printf("Value : %d",CONST);   
		      |  ^~~~~~
                main.c:5:2: error: incompatible implicit declaration of built-in function ‘printf’ [-Werror]
```

**_6. -o name_**
```
		-o is used to create a executable file.

Eg:
#include<stdio.h>
int main()
{
	printf("Hello\n");
	return 0;
}

Compilation : gcc -o main main.c

Observation : A executable file main is created 

Output : ./main  ==> Hello
```

**_7. -save-temps_**
```
		Store the normally temporary intermediate file(*.s, *.i, *.o) permanently.
Eg:
#include<stdio.h>
int main()
{
	printf("Hello\n");
	return 0;
}

Compilation : gcc -o main main.c -save-temps

Observation : main.o main.i main.s files are created.
```

**8. --version_**
```
		Prints the version of the compiler

Observation : gcc --version

Output : gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0                                                            
         Copyright (C) 2019 Free Software Foundation, Inc.
```

**_9. -print-search-dirs_**
```
		Reveal the directories that gcc searches for programs and libraries.

Observation : gcc -print-search-dirs main.c

Output : install : /usr/lib/gcc/x86_64-linux-gnu/9/  
         programs: =/usr/lib/gcc/x86_64-linux-gnu/9/:/usr/lib/gcc/x86_64-linux-gnu/9/:/usr/lib/gcc/x86_64-linux-gnu/:
		    /usr/lib/gcc/x86_64-linux-gnu/9/:/usr/lib/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/9/..
		    /../../../x86_64-linux-gnu/bin/x86_64-linux-gnu/9/:/usr/lib/gcc/x86_64-linux-gnu/9/../../../..
		    /x86_64-linux-gnu/bin/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/9/../../../..
		    /x86_64-linux-gnu/bin/
```

**_10. -print-prog-name_**
```
		gcc -print-prog-name=main.c prints the path to the installation of main.

Observation : gcc -print-prog-name=main.c

Output : main.c
```

**_11. -Wfloat-equal_**
```
		Warn if two floating-point numbers are compared.

Eg :
#include<stdio.h>
int main()
{
float f1 = 4.25;
float f2 = 4.25;
if(f1 == f2)
	printf("f1 == f2\n");
}

Compilation : gcc -Wfloat-equal float_equal.c

Observation : fl.c:8:15: warning: comparing floating point with == or != is unsafe [-Wfloat-equal]
                   8 |        if (f1 == f2) {   
                     |               ^~            
```

**_12. -Winit-self_**

		Warn about variables that are initialized with themselves.
Eg:
#include<stdio.h>
int main()
{
	int i = i;
	printf("i = %d\n",i);
}

Compilation : gcc -Wuninitialized -Winit-self init-self.c

Observation : fl.c:5:5: warning: ‘i’ is used uninitialized in this function [-Wuninitialized]
                 5 | int i = i;   
                   |     ^     
```

**_13. -Wshadow_**
```
		Warn about local variables shadowing another variable.

Eg:
#include<stdio.h>
int main()
{
	int i = 42;	
	if(i == 42)
	{
		printf("i = %d\n",i);
		i = 49;
		printf("i = %d\n",i);
	}
}

Compilation : gcc -Wshadow shadow.c 

Observation : fl.c:10:12: warning: declaration of ‘i’ shadows a previous local [-Wshadow]  
                 10 |        int i = 49; 
                    |            ^             
              fl.c:5:8: note: shadowed declaration is here      
                  5 |    int i = 42;    
                    |        ^         
```

**_14. -dumpversion_**
```
		Print the compiler version (for example, 3.0, 6.3.0 or 7)—and don’t do anything else. 
		This is the compiler version used in filesystem paths and specs.    

Compilation : gcc -dumpversion

Output : 7
```

**15. -time_**
```
		Report the CPU time taken by each subprocess in the compilation sequence.

Eg:
#include<stdio.h>
int main()
{
	printf("hello\n");
	return 0;
}

Compilation : time gcc fl.c

Output : 
	real    0m0.360s   
        user    0m0.047s    
        sys     0m0.172s 
```

**_16. -dumpmachine_**
```
		Print the compiler’s target machine (for example, i686-pc-linux-gnu)-and don’t do anything else.

Compilation : gcc -dumpmachine

Output : x86_64-linux-gnu 
```


**_17. -Wimplicit-function-declaration_**
```
		It gives a warning (or) error whenever a function is used before declared. This option is default in
nature.

Eg :
/* no header file */
int main()
{
	printf("Hello\n");
	return 0;
}

Compilation : gcc main.c

Observation : 
		fl.c:4:4: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
                   4 |    printf("hello");    
                     |    ^~~~~~     
```

**_18. -c option_**
```
		Compiles source files without linking.  

Eg:
#include<stdio.h>
int main()
{
	printf("hello\n");
	return 0;
}

Compilation : gcc -c file.c

Observation : This compilation generated file.o object file
``` 

**_19. -g option_**
```
		generates debug information to be used by GDB debugger

Eg:
#include<stdio.h>
int main()
{
	printf("hello\n");
	return 0;
}

Compilation : gcc -g myfile.c -o myfile
	      gdb myfile
	      (gdb) run
	      Starting program: /home/ubuntu/myfile
	      hello
	      Program exited with code 012.
	      (gdb) quit      

Observation : compiled in gdb debugger
```

**_20. -O option flag_**
```
		Set the compiler's optimization level

			-O0    ->   optimization for compilation time
			-O1    ->   optimization for code size and execution time
			-O2    ->   optimization for code size and execution time
			-O3    ->   optimization for code size and execution time
			-Os    ->   optimization for code size
			-Ofast ->   O3 with fast none accurate math calculations

Eg:
#include<stdio.h>
int main()
{
	printf("Hello\n");
	return 0;
}

Compilation : gcc -O myfile.c -o myfile

Observation : Optimized according to the level

Output : Hello                                
```  
