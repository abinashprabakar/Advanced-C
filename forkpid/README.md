1. forkpid_example

In this program, it is explained about getpid and getppid function.getpid() returns the process ID of the calling 
process. getppid() returns the process ID of the parent of the calling process. Here pid is assinged to fork(). 
When pid == 0 , it is in child process and when pid > 0,it is in parent process.


2. forkpid_example1

It is same as that of the previous program. It prints the Process ID in the first printf statement and Parent Process ID
in the second printf statement.


3. multiple_forkpid

In this program, it is explained that how the pid and ppid is executed in the each fork() system call .
