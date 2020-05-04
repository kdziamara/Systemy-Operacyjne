#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFSIZE 1

int main(int argc, char *argv[]) {
    int fifo = open(argv[0], O_RDONLY);
    int fd_out = open("schowek.txt", O_WRONLY | O_CREAT);
    char buf[BUFFSIZE];

	if (fifo == -1) {
        perror("open");
	    return 1;
    }
    while (read(fifo, &buf, BUFFSIZE) > 0) {
 		if (write(fd_out, &buf, BUFFSIZE) == -1) {
            perror("write");
        }
    }
    
    return 0;
}