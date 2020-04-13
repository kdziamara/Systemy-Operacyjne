#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024

int kopiuj(char*, char*);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Too few arguments\n");
        return 1;
    }
    kopiuj(argv[1], argv[2]);
}

int kopiuj(char *input, char *output) {
    int fd_in = open(input, O_RDONLY);
    int fd_out = open(output, O_WRONLY);
    if (fd_out == -1 || fd_in == -1) {
        perror("Error while opening files");
        return 1;
    }

    char *buf = (char *) calloc(BUFF_SIZE, sizeof(char));

    
    int readed = read(fd_in, buf, BUFF_SIZE);
    while (readed > 0) {
        //printf("%s\n\n", buf);
        if (write(fd_out, buf, readed) < 0) {
            perror("Error while writing");
        }

        readed = read(fd_in, buf, BUFF_SIZE);
    }

    if (readed < 0) {
        perror("Error while reading");
    }

    free(buf);

    if (close(fd_in) == -1 || close(fd_out) == -1) {
        perror("Error while closing files");
        return 1;
    }

    return 0;
}