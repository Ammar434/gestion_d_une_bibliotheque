CFLAGS = -g -Wall -Wextra -pedantic 
CC = gcc

PROGRAMS = main_hash main main_jeux_tests_exo1 main_jeux_tests_exo2


.PHONY:	all clean

all: $(PROGRAMS)

main_jeux_tests_exo2: main_jeux_tests_exo2.o  entreeSortieH.o biblioH.o
	$(CC) -o $@ $(CFLAGS) $^

main_jeux_tests_exo1: main_jeux_tests_exo1.o  entreeSortieLC.o biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^

main: main.o  entreeSortieLC.o biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^

entreeSortieLC.o: entreeSortieLC.c
	$(CC) -c $(CFLAGS) entreeSortieLC.c 

biblioLC.o: biblioLC.c
	$(CC) -c $(CFLAGS) biblioLC.c

main_hash: mainHash.o  entreeSortieH.o biblioH.o
	$(CC) -o $@ $(CFLAGS) $^

simulationLC: simulationLC.o entreeSortieLC.o biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^

simulationH: simulationH.o entreeSortieH.o biblioH.o
	$(CC) -o $@ $(CFLAGS) $^
	
entreeSortieH.o: entreeSortieH.c
	$(CC) -c $(CFLAGS) entreeSortieH.c 

biblioH.o: biblioH.c
	$(CC) -c $(CFLAGS) biblioH.c

clean:
	rm -f *.o *~ $(PROGRAMS) simulationLC simulationH
