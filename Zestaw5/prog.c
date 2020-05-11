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

#define BUFFER_SIZE 1024
#define FILE_NAME "numer.txt"

int randRange(int from, int to) {
	return from + (rand() % (to - from));
}

int getNumberFromFile(char *fileName) {
	char *buffer = (char *)	malloc(BUFFER_SIZE * sizeof(char));
	int fdIn = open(fileName, O_RDONLY);
	int readSize;
	if (fdIn == -1) {
        perror("Error while opening files");
        return 1;
	}
	readSize = read(fdIn, buffer, BUFFER_SIZE);
	if (readSize == 0) {
		perror("empty file");
		exit(1);
	}
	if (readSize == -1) {
		perror("Error while reading");
		exit(1);
	}
	close(fdIn);
	int number = atoi(buffer);
	free(buffer);
	return number;
}

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
	int seed = time(NULL);
	srand(seed);
	if (argc != 3) {
		perror("wrong argument nuber");
		return 1;
	}

	int pid = getpid();
	semid mySemaphore = semOpen(argv[1]);

	for (int i = 0; i < 10; i++) {
		usleep(100);
		printf("pid: %d before critical\n", pid);
		usleep(100);
		semP(mySemaphore);
		printf("pid: %d critical\n", pid);
		int n = getNumberFromFile(FILE_NAME);
		usleep(randRange(100,500) * 1000);
		setNumberToFile(FILE_NAME, n + 1);
		usleep(100);
		semV(mySemaphore);
		printf("pid: %d after critical\n", pid);
		usleep(100);
	}

	return 0;
}
