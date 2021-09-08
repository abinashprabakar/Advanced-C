Static Library(.a) : Library of object code which is linked with, and becomes part of the application. Static Linking 			   creates larger size executable files and need more space on disk and main memory. Another name
		     for static library is "archive files", so extension is .a
		     Examples of static libraries are .a files in linux and .lib files in windows

Compilation : gcc -static filename.c -o filename


Steps to create static library :
```
1. To make your own library, you must first compile each of your source files into object files.

2. Now, you are ready with object files : sum.o, mul.o, print.o to create your own static library.

3. Now, you have to use the ar command to create the library and pu the objects in it. The archiver also 
   known as ar, is a Unix utility that maintains groups of files as a single archive file. 

4. The command to create static library say libabc.a from sum.o mul.o print.o is
	$ar -rcsv libabc.a sum.o mul.o print.o

	r -> replace objects in the library with the new ones on the command line. Since the library doesn't contain
	     any objects, this effectively means add them to the library. The next time you run it, it will replace
	     the old versions with the new versions.

	c -> do not warn if library is newly created. There are also options for extracting and deleting objects in
	     the library.

	s -> tells ar to create a symbol table, which is something extra that gcc needs when using a library.

	v -> means verbose, which tells ar to keep you informed about what it's doing.

5. You can list out the object files in given library. The command is
	$ar -t libabc.a

	t -> displays the content of archive file.

6. To compile with your own static library use the llibrary of cc command preceded by source filename
	$gcc statp.c libabc.a -o statp

	Here statp is an executable file but still it is not statically linked.
```
