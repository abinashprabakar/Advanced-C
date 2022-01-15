CC = gcc
CFLAGS = -g -fsanitize=address -static-libasan

all : memory_corruption

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean:
	rm -rf *.o memory_corruption
