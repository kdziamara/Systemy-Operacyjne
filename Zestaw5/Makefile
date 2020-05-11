all:  sem.o semuse.x prog.x powielacz.x 

sem.o: sem.c
	gcc -c sem.c && ar rv libsem.a sem.o 

%.x: %.c
	gcc $^ -o $@ -pthread -L. -lsem 

clean: 
	rm *.x *.o *.a
