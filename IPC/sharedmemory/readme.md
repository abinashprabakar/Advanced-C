# Shared Memory

	Shared Memory allows two or more processes to share the same region (usually referred to as a segment) of
	physical memory. Since a shared memory segment becomes part of a process's user space memory, no kernel
	intervention is required for IPC. All that is required is that one process copies data into the shared memory,
	That data is immediately available to all othet processers sharing the same segment.

Steps for using Shared Memory
```
	1. Call shmget() to create a new shared memory segment or obtain the identifier of an existing segment(i.e one
	   created by another process). This call returns a shared memory identifier for use in later calls.

	2. Use shmat() to attach the shared memory segment; that is, make the segment part of the virtual memory of
	   the calling process.

	3. At this point, the shared memory segment can be treated just like any other memory available to the program.
	   In order to refer to the shared memory, the program uses the addr value returned by the shmat() call, which
	   is a pointer to the start of the shared memory segment in the process's virtual address space.

	4. Call shmdt() to detach the shared memory segment. After this call, the process can no longer refer to the
	   shared memory. This step is optional, and happens automatically on process termination.

	5. Call shmctl() to delete the shared memory segment. The segment will be destoyed only after all currently
	   attached processes have detached it. Only one process needs to perform this step.
```
