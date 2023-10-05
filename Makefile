CC = gcc
CFLAGS = -g
CPPFLAGS = -Wall

all: router

router: router.o
	$(CC) -o router router.o

router.o: router.c
	$(CC) -o router.o -c $(CFLAGS) $(CPPFLAGS) router.c

clean:
	rm -f *.o
	rm -f router