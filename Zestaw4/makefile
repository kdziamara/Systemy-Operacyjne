CC = gcc
CFLAGS = -std=c99 -Wall
ZAD = prodkons.x konsument.x producent.x fifo.x

.PHONY: all clean cleano

all: $(ZAD)

prodkons.x: prodkons.o
konsument.x: konsument.o
producent.x: producent.o
fifo.x: fifo.o

%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^

cleano:
	$(RM) -rf *.o
clean:
	$(RM) -rf *.o *.x .DS_Store schowek.txt