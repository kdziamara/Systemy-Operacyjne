// #include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include "sem.h"

#define TOM "Thomas_the_tank_engine"

typedef sem_t *semid;


int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);
	if (argc == 2) {
		semid thomas;
		switch(argv[1][0]) {
			case 'i':
				thomas = semCreate(TOM, 1);
				semInfo(thomas);
				break;
			case 'r':
				semRemove(TOM);
				break;
			case 'p':
				thomas = semOpen(TOM);
				semP(thomas);
				semInfo(thomas);
				break;
			case 'v':
				thomas = semOpen(TOM);
				semV(thomas);
				semInfo(thomas);
				break;
			case 'q':
				thomas = semOpen(TOM);
				semInfo(thomas);
				break;
			default:
				printf("wrong argument\n");
		}
	}
	return 0;
}
