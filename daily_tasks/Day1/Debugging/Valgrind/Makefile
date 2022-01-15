CC = gcc
CFLAGS = -g -O0

all : memory_corruption

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o memory_corruption
