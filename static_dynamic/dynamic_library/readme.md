dynamic library(.so) : It helps in dynamic linking i.e,. dynamic load time linking and dynamic run time linking.
		       Another name of dynamic library is "shared object" or "DLL files" in windows, so the 
		       extension is .so in linux and .dll(Dynamic Link Library) in windows.
		       When the linker is dynamically linking with dynamic libraries, required function definitions			       are not copied to executable file. Thus executable file size is less.

Steps to create Dynamic Library:
```
1. PIC(Position Independent Code) is commonly used for shared libraries, so that the same library code can be loaded in
a location in each program address space where it will not overlap any other uses of memory.
   The commands to create PIC object files is
		gcc -c -fpic mul.c
		gcc -c -fpic sum.c
		gcc -c -fpic print

	This will give you .o object files.

2. The command to create to dynamic library is
		gcc -shared -o libabc.so sum.o mul.o print.o
   libabc.so is shared object.

3. Now, the file command result shows as follows,
		$file libabc.so
		libabc.so : ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked,....

4. Now, linking with your own dynamic library,
		cc main.c ./libabc.so main

	Here main is the executable file

5. ldd -> used to know the dependencies.
```
