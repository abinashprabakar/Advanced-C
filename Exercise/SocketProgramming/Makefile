CC = gcc
FLAGS = -g -O0

all : server client 

%.o : %.c
	$(CC) $(FLAGS) -o $^

clean:
	rm -rf *.o server client
