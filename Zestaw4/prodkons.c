#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFSIZE 1

int main() {
    int fd[2];
    int fd_in = open("magazyn.txt", O_RDONLY);
    int fd_out = open("schowek.txt", O_WRONLY | O_CREAT);
    char buf[BUFFSIZE];

    if (pipe(fd) == -1) {
        perror("pipe");
    }

    if (fork()) {
        // Konsumer
        close(fd[1]);

        while(read(fd[0], &buf, BUFFSIZE) > 0) {
            printf("Catched: %s\n", buf);
            write(fd_out, &buf, BUFFSIZE);
            usleep(rand() % 100);
        }

        close(fd[0]);
        close(fd_out);
        wait(NULL);
    } else {
        // Producent
        close(fd[0]);

        while (read(fd_in, &buf, BUFFSIZE) > 0) {
            printf("Sending: %s\n", buf);
            write(fd[1], &buf, BUFFSIZE);
            usleep(rand() % 100);
        };

        close(fd[1]);
        close(fd_in);
    }
    return 0;
}