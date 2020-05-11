#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include "sem.h"

#define SEM_NAME "tomek"
#define FILE_NAME "numer.txt"
#define BUFFER_SIZE 1024

void setNumberToFile(char *fileName, int number) {
	char *buffer = (char *)	malloc(BUFFER_SIZE * sizeof(char));
	sprintf(buffer, "%d", number);
    int fdOut = open(fileName, O_WRONLY | O_CREAT, S_IRWXU);
	if (fdOut == -1) {
        perror("Error while reading files");
		exit(1);
	}
	if (write(fdOut, buffer, BUFFER_SIZE) == -1) {
		perror("Error while writing");
		exit(1);
	}
	close(fdOut);
	free(buffer);
}


int main(int argc, char* argv[]) {
	if (argc != 3) {
		perror("wrong argument nuber");
		return 1;
	}
	setNumberToFile(FILE_NAME, 0);
	semCreate(SEM_NAME, 1);
	int processNumber = atoi(argv[2]);
	// int childPids[processNumber];

	for (int i = 0; i < processNumber; i++) {
		int childPid = fork();
		if (childPid == -1) {
			perror("fork error");
			return 1;
		}
		else if (childPid == 0)	{
			char* newArgv[] = {argv[1], SEM_NAME, argv[2],  NULL};
			execv(argv[1], newArgv);
		}
	}

	for (int i = 0; i < processNumber; i++) {
		wait(NULL);
	}

	semRemove(SEM_NAME);
	return 0;
}
