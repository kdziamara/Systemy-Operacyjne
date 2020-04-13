CC = gcc
CFLAGS = -std=c99 -Wall
ZAD = procesy.x drzewo1.x drzewo2.x macierzysty.x potomny.x zombie.x orphan.x execute.x cleano

.PHONY: all clean cleano

all: $(ZAD)

main.x: main.o procinfo.o
kopiuj.x: kopiuj.o
procesy.x: procesy.o procinfo.o
drzewo1.x: drzewo1.o procinfo.o
drzewo2.x: drzewo2.o procinfo.o
macierzysty.x: macierzysty.o procinfo.o
potomny.x: potomny.o procinfo.o
zombie.x: zombie.o procinfo.o
orphan.x: orphan.o procinfo.o
execute.x: execute.o procinfo.o
main.o: main.c
procinfo.o: procinfo.c procinfo.h

%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^

cleano:
	$(RM) -rf *.o
clean:
	$(RM) -rf *.o *.x .DS_Store