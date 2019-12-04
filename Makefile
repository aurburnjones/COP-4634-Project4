CFLAGS = -g -Wall
CC = gcc

objects = fileSystem.o disk.o inode.o

fileSystem : $(objects)
	$(CC) $(CFLAGS) -o fileSystem $(objects)

fileSystem.o : fileSystem.c fileSystem.h
disk.o : disk.c disk.h
inode.o : inode.c inode.h

.PHONY : clean
clean :
	rm fileSystem $(objects)
