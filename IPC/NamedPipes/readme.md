**Named Pipes**
```
	A named pipe is a named, one-way or duplex pipe for communication between the pipe server and one or more pipe 
clients. Named pipes can be used to provide communication between processes on the same computer or between processes 
on different computers across a network.
	Another name for named pipe is FIFO (First-In-First-Out).
	
	Syntax : int mkfifo(const char *pathname, mode_t mode);
```

**named_pipe_fileoperation.c** - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/IPC/NamedPipes/named_pipe_fileoperation.c">code</a>

		This program implements the file operation through the named pipe.

**named_pipe_fork.c** - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/IPC/NamedPipes/named_pipe_fork.c">code</a>

		This program implements the fork() system call through the named pipe.

**named_pipe_readwrite.c** - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/IPC/NamedPipes/named_pipe_fork.c">code</a>

		This program implements the read & write operation through the named pipe.
