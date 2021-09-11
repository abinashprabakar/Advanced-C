CC = gcc
FLAGS = -g -O0 -o

all : named_pipe_fileoperation named_pipe_fork named_pipe_readwrite

%.o : %.c
	$(CC) $(FLAGS) $^

clean : 
	rm -rf *.o named_pipe_fileoperation named_pipe_fork named_pipe_readwrite
