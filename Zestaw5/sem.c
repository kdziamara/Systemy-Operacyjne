#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <errno.h>

typedef sem_t *semid;

semid semCreate(char *name, int value) {
	sem_t *sem_id = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (sem_id == SEM_FAILED) {
		perror("Creating semaphore");
		exit(1);
	} else {
		printf("Semaphore %s created\n", name);
	}
	return sem_id;
}

void semRemove(char *name) {
	if (sem_unlink(name) == -1) {
		perror("Remove semaphore");
		exit(1);
	} else {
		printf("Semaphore %s removed\n", name);
	}
}

semid semOpen(char *name) {
	sem_t *sem_id = sem_open(name, 0);
	if (sem_id == SEM_FAILED) {
		perror("Open semaphore");
		exit(1);
	} else {
		printf("semaphore %s opened\n", name);
	}
	return sem_id;
}

void semClose(semid sem_id) {
	if (sem_close(sem_id) == -1) {
		perror("Close semaphore");
		exit(1);
	} else {
		printf("Semaphore closed\n");
	}
}

void semInfo(semid sem_id) {
	int value;
	if (sem_getvalue(sem_id, &value) == -1) {
		perror("Value of semaphore");
		exit(1);
	} else {
		printf("Value of semaphore %d\n", value);
	}
}

void semP(semid sem_id) {
	if (sem_wait(sem_id) == -1) {
		perror("Passeren semaphore");
		exit(1);
	} else {
		printf("Semaphore passeren\n");
	}
}

void semV(semid sem_id) {
	if (sem_post(sem_id) == -1) {
		perror("Vrijgeven semaphore");
		exit(1);
	} else {
		printf("Semaphore vrijgeven\n");
	}
}
