CC = gcc
CFLAGS = -g -O0

all : debug

%.o : %.c
	$(CC) $(CFLAGS) -o $^

clean :
	rm -rf *.o debug
