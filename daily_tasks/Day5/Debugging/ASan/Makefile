CC = gcc
CFLAGS = -g -O0 -fsanitize=address

all : asan

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean :
	rm -rf *.o asan
