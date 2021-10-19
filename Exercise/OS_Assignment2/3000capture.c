/* 3000capture.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int result_pid = -1;
int result_status = 0;
int child_exited = 0;

void signal_handler(int the_signal)
{
        if (the_signal == SIGCHLD) {
                result_pid = wait(&result_status);
                if (result_pid == -1) {
                        return;
                }
                
                child_exited = 1;
        }
}

int parent(pid_t child_pid, char *command)
{
        int count = 0;
        const int bufsize = 256;
        char buf[bufsize];

        printf("Waiting.");
        fflush(stdout);

        while (!child_exited) {
                sleep(1);
                write(1, ".", 1);
        }

        printf("\n");
        
        if (result_pid == child_pid) {
                count += snprintf(buf + count, bufsize,
                                  "Child %d terminated", child_pid);
                if (WIFEXITED(result_status)) {
                        count += snprintf(buf + count, bufsize,
                                          " normally with status %d",
                                          WEXITSTATUS(result_status));
                } else if (WIFSIGNALED(result_status)) {
                        count += snprintf(buf + count, bufsize,
                                          " with signal %d",
                                          WTERMSIG(result_status));
                }
                
                puts(buf);
                return 0;
        } else if (result_pid == -1) {
                printf("No child to wait for.\n");
                return -1;
        } else {
                printf("wait returned unknown value %d\n", result_pid);
                return result_pid;
        }
}

int child(char *command, char *input_fn, char *output_fn, char *argv[])
{
        extern char **environ;
        int fd;

        close(1);
        fd = creat(output_fn, 0644);
        if (fd == -1) {
                fprintf(stderr, "Could not create %s for output.\n",
                        output_fn);
                exit(-3);
        }
        dup2(fd, 1);

        close(0);
        fd = open(input_fn, O_RDONLY);
        if (fd == -1) {
                fprintf(stderr, "Could not open %s for input.\n",
                        output_fn);
                exit(-4);
        }
        dup2(fd, 0);
        
        execve(command, argv, environ);
        fprintf(stderr, "execve of %s failed.\n", command);
        return(-1);
}

int main(int argc, char *argv[], char *envp[])
{
        char *command;
        char *input_fn;
        char *output_fn = "3000capture.log";
        
        pid_t pid;
        
        struct sigaction signal_handler_struct;
        
        memset(&signal_handler_struct, 0, sizeof(signal_handler_struct));
        signal_handler_struct.sa_handler = signal_handler;
        
        if (sigaction(SIGCHLD, &signal_handler_struct, NULL)) {
                fprintf(stderr, "Couldn't register SIGCHLD handler.\n");
        }

        if (argc < 3) {
                fprintf(stderr,
                        "Usage: %s <command> <input file> [command args]\n"
                        "By default saves data to %s; set CAPTURE to change.\n",
                        argv[0], output_fn);
                exit(-1);
        }
        
        command = argv[1];
        input_fn = argv[2];

        pid = fork();

        if (pid == -1) {
                fprintf(stderr, "Fork failed.\n");
                exit(-2);
        } else if (pid == 0) {
                argv[2] = command;
                return child(command, input_fn, output_fn, argv + 2);
        } else {
                return parent(pid, command);
        }
}