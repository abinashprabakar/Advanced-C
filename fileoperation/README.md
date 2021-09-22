
file_read_write.c - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/fileoperation/file_read_write.c">code</a>

		In this program it is explained that how a basic file operation is executed. Here we are opening a file in 
		read|write mode. At first the data present in the text file is read and then printed along with the new string given 
		in the program. If any error occurs, **strerror** function displays the error number.

dup_operation.c - <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/fileoperation/dup_operation.c">code</a>
	
		The dup2() system call performs the same task as dup(), but instead of using the lowest-numbered
		unused file descriptor, it uses the file descriptor number specified in newfd.  In other words, the
		file descriptor newfd is adjusted so that it now refers to the same open file description as oldfd.

dup2_operation.c -  <a href = "https://github.com/abinashprabakar/Advanced-C/blob/main/fileoperation/dup2_operation.c">code</a>
	
		The dup() system call allocates a new file descriptor that refers to the same open file description as
		the descriptor oldfd.
