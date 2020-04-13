CC = gcc
CFLAGS = -std=c99 -Wall
ZAD = main.x kopiuj.x procesy.x lider.x

.PHONY: all clean

all: $(ZAD)

main.x: main.o procinfo.o
kopiuj.x: kopiuj.o
lider.x: lider.o procinfo.o
procesy.x: procesy.o procinfo.o
main.o: main.c
procinfo.o: procinfo.c procinfo.h
kopiuj.o: kopiuj.c
procesy.o: procesy.c
lider.o: lider.c

%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) -rf *.o *.x .DS_Store