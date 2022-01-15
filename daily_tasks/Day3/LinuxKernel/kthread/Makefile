PWD := $(shell pwd)
obj-m += spin_lock.o thread.o mutex.o semaphore.o atomic.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean


