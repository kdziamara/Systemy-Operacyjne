CC = gcc
CFLAGS = -std=c99 -Wall
ZAD = obsluga.x wysylaj.x cleano

.PHONY: all clean cleano

all: $(ZAD)

obsluga.x: obsluga.o procinfo.o
wysylaj.x: wysylaj.o procinfo.o

%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^

cleano:
	$(RM) -rf *.o
clean:
	$(RM) -rf *.o *.x .DS_Store