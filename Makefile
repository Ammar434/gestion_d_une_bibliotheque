CFLAGS = -g -Wall -Wextra -pedantic
CC = gcc

PROGRAMS = main_tests

.PHONY:	all clean

all: $(PROGRAMS)

main_tests: main.o  entreeSortieLC.o biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^

main2.o: main.c
	$(CC) -c $(CFLAGS) main.c

entreeSortieLC.o: entreeSortieLC.c
	$(CC) -c $(CFLAGS) entreeSortieLC.c 

biblioLC.o: biblioLC.c
	$(CC) -c $(CFLAGS) biblioLC.c


clean:
	rm -f *.o *~ $(PROGRAMS)
