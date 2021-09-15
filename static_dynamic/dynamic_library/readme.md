dynamic library(.so) : 
			
		It helps in dynamic linking i.e,. dynamic load time linking and dynamic run time linking.
		Another name of dynamic library is "shared object" or "DLL files" in windows, so the 
		extension is .so in linux and .dll(Dynamic Link Library) in windows.
		When the linker is dynamically linking with dynamic libraries, required function definitions
		are not copied to executable file. Thus executable file size is less.

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
	ldd is a tool that allows us to see recursive shared library dependencies. That means we can see the
	complete list of all shared libraries an artifact needs at runtime. It also allows us to see where these
	dependencies are located.

6. ls -h -> to show the total size occupied by the shared library
		Eg : total 52k
```

<b> Using <i>LD_LIBRARY_PATH</i></b>

	In Linux, the environment variable LD_LIBRARY_PATH is a colon-separated set of directories where libraries
	should be searched for first, before the standard set of directories; this is useful when debugging a new
	library or using a nonstandard library for special purposes.
```
$echo $LD_LIBRARY_PATH
```

There is nothing in there. Let us fix that by prepending our working directory to the existing LD_LIBRARY_PATH :
```
$ LD_LIBRARY_PATH = /home/abinash/Advanced-C/static_dynamic/dynamic_library : $LD_LIBRARY_PATH
export LD_LIBRARY_PATH  
$ ./output

./output : error while loading shared libraries: libabc.so: cannot open shared object file: No such file or directory
``` 
What happened? Our directory is in LD_LIBRARY_PATH, but we did not export it. In Linux, if you do not export the change
to an environment variable, they will not be inherited by the child processes. The loader and our test program did not
inherit the changes we made. Thankfully, the fix is easy,
```
$ export LD_LIBRARY_PATH = /home/abinash/Advanced-C/static_dynamic/dynamic_library : $LD_LIBRARY_PATH
$ ./output
This is a shared library test ...
Hello, I am a shared library
```
Good, it worked! LD_LIBRARY_PATH is a great for quick tests and for systems on which you do not have admin privileges.
As a downside, however, exporting the LD_LIBRARY_PATH variable means it may cause problems with other programs you run
that also rely on LD_LIBRARY_PATH if you do not reset it to its previous state when you are done.

<b> Using<i>rpath</i></b>

Now let's try (first we will clear LD_LIBRARY_PATH to ensure it is rpath that is finding our library). Rpath, or the
run path, is a way of embedding the location of shared libraries in the executable itself, instead of relying on default
locations or environment variables. We do this during the linking stage. Notice the lengthy name -Wl,
-rpath = /home/abinash/Advanced-C/static_dynamic/dynamic_library option. The -Wl portion sends comma-seperated options
to the linker, so well it to send the -rpath oprion to the linker with our working directory.
```
$ unset LD_LIBRARY_PATH
$ gcc -L/home/abinash/Advanced-C/static_dynamic/dynamic_library -Wl,
-rpath = /abinash/Advanced-C/static_dynamic/dynamic_library -Wall -o output main.c -lfoo
$ ./output
This is a shared library test...
Hello, I am a shared library
```
Excellent, it worked. The rpath method is great because each program gets to list its shared library locations indepen-
dently, so there are no issues with different programs looking in the wrong paths like there were for LD_LIBRARY_PATH.

<b><i>rpath vs LD_LIBRARY_PATH </b></i>

There are a few downsides to rpath, however. First, it requires that shared libraries be installed in a fixed location
so that all users of your program will have access to those libraries in those locations. That means less flexibility
in system configuration. Second, if that library refers to a NFS mount or other network drive, you may experience
undesirable delays - or worse - on program startup.

<b><i> Using ldconfig to modify ld.so </b></i>

What if we want to install our library so everybody on the system call use it? For that, you will need admin privileges.
You will need this for two reasons: first, to put the library in a standard location, probably /usr/lib or
/usr/local/lib, which normal users do not have write access to. Second, you will need to modify the ld.so config and
cache. As root, do the following:

	$ cp /abinash/Advanced-C/static_dynamic/dynamic_library/libabc.so /usr/lib
	$ chmod 0755 /usr/lib/libabc.so
