**IPCPipe** - <a href = "https://github.com/abinashprabakar/Advanced-C/tree/main/IPC/IPCPipe">directory</a>

		A Pipe is a technique used for inter process communication. A pipe is a mechanism by which the output
		of one process is directed into the input of another process. Thus it provides one way flow of data
		between two related processes.  Process A and Process B, need to communicate. In such a case, it is
		important that the process which writes, closes its read end of the pipe and the process which reads,
		closes its write end of a pipe. 

**NamedPipes** - <a href = "https://github.com/abinashprabakar/Advanced-C/tree/main/IPC/NamedPipe">directory</a>

		A FIFO, also known as a named pipe, is a special file similar to a pipe but with a name on the
		filesystem. Multiple processes can access this special file for reading and writing like any ordinary
		file. A named pipe is a named, one-way or duplex pipe for communication between the pipe server and
		one or more pipe clients.

**sharedmemory** - <a href = "https://github.com/abinashprabakar/Advanced-C/tree/main/IPC/sharedmemory">directory</a>

		Shared Memory allows two or more processes to share the same region (usually referred to as a segment)
		of physical memory. Since a shared memory segment becomes part of a process's user space memory, no
		kernel intervention is required for IPC. All that is required is that one process copies data into the
		shared memory,that data is immediately available to all othet processers sharing the same segment.	
