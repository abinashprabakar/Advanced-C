**_Static Library :_** <a href = "https://github.com/abinashprabakar/Advanced-C/tree/main/static_dynamic/static_library ">code</a>

```
Static libraries, while reusable in multiple programs, are locked into a program at compile time._**
```

**_Dynamic Library :_** <a href = "https://github.com/abinashprabakar/Advanced-C/tree/main/static_dynamic/dynamic_library ">code</a>
```
Dynamic, or shared libraries on the other hand, exist as separate files outside of the executable file.
```

_Main differences between static and dynamic library are,_

```
1. Linking time

	Static : happens as the last step of the compilation process. After the program is placed in the memory.

	Dynamic : shared libraries are added during the linking process when executable files and libraries are 
		  added to the memory.

2. Means

	Static : Performed by Linker.

	Dynamic : Performed by the operating system.

3. Size

	Static : much bigger, because external programs are built in the executable file.

	Dynamic : much smaller, because there is only one copy of the dynamic library that is kept in memory.

4. Time :

	Static : takes longer to execute, because loading into the memory happens every time while executing.

	Dynamic : faster, because shared library code is already in memory.

5. External file linkages

	Static : the executable file will have to be recompiled if any changes were applied to external files.

	Dynamic : in the case of shared libraries, no need to recompile the executable.
