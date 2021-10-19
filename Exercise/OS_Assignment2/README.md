#Solutions :

1. If we read from /dev/null, what data do we get? How can you verify this?

		We get no data, the file always reads as being empty (no matter what is written to it).  We can
		confirm this by running "cat /dev/null/  or hexdump -Cv /dev/null/", we'll see that the file is always
		an empty file.

2. 3000capture requires commands to be fully qualified pathnames. How can you modify 3000capture so that  if a command
doesn't start with a /, 3000capture searches the current PATH to find the right program? If path isn't defined it 
should search a default set of directories.

		We can copy the function find_binary() from 3000shell.c (lines 92 - 134) and then call it with the 
		following code added to 3000capture, replacing the original 92:

			#define BUFFER_SIZE 1<<16
			char bin_fn[BUFFER_SIZE];
			char *default_path = "/usr/bin:/bin";
			char *path = getenv("PATH");
			if(!path) {
				path = default_path;
			}
			find_binary(command, path, bin_fn, BUFFER_SIZE);

			execv(bin_fn, arv, environ);

3. What is the purpose of fflush() call in parent() at line 36? Why isn't it needed elsewhere in parent()?

		fflush() is needed to flush the C library standard I/O buffers so the "Waiting." appears immediately
		when the previous printf() is called. Normally C library functions buffer output to the terminal and
		only output when a newline is output; fflush() forces the C library to do write immediately.

4. How could you fix 3000capture so it sends its output to the file specified by the CAPTURE environment variable? If
there is no CAPTURE environment variable, it should use the same default as it does currently.

		First, replace the declaration of output_fn in main() on line 101 with :

				char *output_fn;
				char *output_fn_default = "3000capture.log";

		Then, insert at line 124 (or elsewhere in main(), just as long as it is before the call to child) the
		following:

				output_fn = getenv("CAPTURE");
				if(!output_fn) {
					output_fn = output_fn_default;
				}

		Here we get the value of the environment variable CAPTURE, and if it doesn't exist we use the default
		value.

5. How many processes does countdown.sh create, and how many executables does it run? How can you verify this using
bpftrace?

		If we run execsnoop bpftrace script and then run countdown.sh, we get something like the following
		output:

				Attaching 3 probes...
				TIME(ms)   PID   ARGS
				14183      5962  ./countdown.sh
				14189      5963  seq 10 -1 1
				14195      5964  sleep 1
				15200      5965  sleep 1
				16203      5966  sleep 1
				17207      5967  sleep 1
				18211      5968  sleep 1
				19214      5969  sleep 1
				20217      5970  sleep 1
				21221      5971  sleep 1
				22225      5972  sleep 1
				23228      5973  sleep 1


		From this we can see that seq was run once and sleep was run 10 times, and each got its own sequential
		PID. Thus, countdown.sh runs 2 executables and creates 11 processes.

		(Note that echo is an executable, but it is also built in to bash and by default bash uses the built-in
		echo. If we replace echo with /usr/bin/echo, we'll get a process for each line printed, creating 11
		additional processes, each running the echo bianry).

6. What is child_exited used for? Why is it needed?

		Child_exited is needed so signal_handler() can communicate with parent() that the child process has
		terminated. We need this, or something similar, as signal handlers should minimize what they do as they
		can be called when the main thread is doing arbitrary things, and so modifying data structures or
		making system calls could mess up the main execution of the program.

7. How can you create a shell script that sends a SIGTERM signal signal to whatever process that ran it (its parent)?
What happens when you run 3000capture on it?

		Here is kill-parent.sh:

		------
		#!/bin/bash
		kill $PPID
		echo parent was killed, PPID is $PPID
		------

		When you run this, any output of kill-parent.sh is put in 3000capture.log. 
		On the terminal you'll see this:

		Waiting. Terminated

		The terminated is the default message a program outputs when it receives a SIGTERM signal.

		To get a clearer idead what has happened, here's an enhanced version of kill-parent.sh:

		------
		#!/bin/bash

		echo Killing $PPID
		kill $PPID
		echo Signal sent to parent
		sleep 1
		echo Current Processes for user $USER:
		ps -U $USER -o pid, ppid, cmd
		------

		If you run this version with ./3000capture ./kill-parent.sh /dev/null, you'll get output like this in
		3000capture.log (the output to the terminal is unchanged).

		Killing 6307
		Signal sent to parent
		Current Processes for user student:
			PID	PPID   CMD
			716	   1   /lib/systemd/systemd --user
			718	 716   (sd-pam)
		       6215	6126   sshd: student@pts/0
		       6216	6215   -bash
		       6308	   1   /bin/bash ./kill-parent.sh
		       6310	6308   ps -u student -o pid,ppid,cmd

		Note how the kill-parent process, 6308, now has a parent of 1. Its parent process died so it is now the
		parent of init/systemd.

8. How can you verify that the shell script from the previous question is actually sending the right using bptrace?

		If we run the killsnoop.bt bpftrace script, we'll see output like this:

		abinash@comp3000:~$ sudo bpftrace /usr/local/share/bpftrace/tools/killsnoop.bt
		[sudo] password for abinash:
		Attaching 3 probes...
		Tracing kill() signals... Hit Ctrl-C to end.
		TIME		PID 	COMM		SIG TPID RESULT
		14:06:25	6425	kill-parent.sh	15  6424 0

		Here this means that kill-parent.sh received signal 15. If we check the numbering of signals (say,
		with "man 7 signal"), we'll see that SIGTERM is 15.

9. How could you change 3000capture so that when it receives a SIGUSR1 signal it.
   * Prints "SIGUSR1 RECEIVED, shutting down".
   * Sends a SIGTERM signal to its child.
   * Waits atleast one second.
   * If the child has terminated, it reports how the child has terminated, whether from a signal or whether it returned
     normally.
   * If the child has not terminated, it reports "Child still running, aborting" and exits with a return value of -10.

		First, we need to register the signal handler by adding a call to sigaction in main around line 113:

         		if (sigaction(SIGUSR1, &signal_handler_struct, NULL)) {
                 		fprintf(stderr, "Couldn't register SIGUSR1 handler.\n");
         		}

		Next, we need to make the child PID accessible in the signal handler. We can do this by storing it in
		a global variable.  One way is to change the declaration of parent():

			int parent(pid_t the_child_pid, char *command)

		and then making child_pid global, adding this to the top of the file:

			pid_t child_pid;

		We then assign the global at the top of parent():

		  	child_pid = the_child_pid;

		We then need to modify signal_handler to handle SIGUSR1.  Add the following code to the top of
		signal_handler():

         		if (the_signal == SIGUSR1) {
                 		printf("\nSIGUSR1 received, shutting down.\n");
                 		kill(child_pid, SIGTERM);
                 		child_killed = 1;
         		}

		We add this declaration at the top of the file to make child_killed global:

  			int child_killed = 0;

		We then change parent() to use the child_killed flag (replacing lines 38-41):

        		while (!child_exited) {
                		if (child_killed) {
                        		handle_killed_child();
                		}	
                		sleep(1);
                		write(1, ".", 1);
        		}

		And finally we define a function handle_killed_child(). Note that this function always terminates the
		parent with the call to exit().

			void handle_killed_child(void)
			{
        			sleep(1);

        			if (child_exited) {
                			if (WIFEXITED(result_status)) {
                        			printf("Child successfully terminated with status %d\n",
                               			WEXITSTATUS(result_status));
                			
					} 
					else if (WIFSIGNALED(result_status)) {
                        			printf("Child terminated with signal %d\n",
                               			WTERMSIG(result_status));
                			} 
	
					else {
                        			printf("Child exited in a weird way.\n");
                			}
                			
					exit(0);
        			} 
				
				else {
			                printf("Child still running, aborting.\n");
        			        exit(-10);
        			}
			}
