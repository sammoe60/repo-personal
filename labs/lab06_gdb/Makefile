CC = g++

all: date

date:	main.cc Date.o Exceptions.o
	$(CC) -g -Wall -o date main.cc Date.o Exceptions.o

Date.o:	Date.cc Date.h Debug.h
	$(CC) -g -Wall -c -o Date.o Date.cc

Exceptions.o:	Exceptions.cc Exceptions.h
	$(CC) -g -Wall -c -o Exceptions.o Exceptions.cc

clean:
	rm -f *date *.o
