CC = gcc
CFLAGS=-g -O0

all: message_insert message_read_from_queue queue_fork_process

%.o:%.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o message_insert message_read_from_queue queue_fork_process