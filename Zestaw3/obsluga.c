#include "procinfo.h"
#include <stdlib.h>
#include <signal.h>

void ignore_handler(int sig) {
    printf("I'm doing nothing... :)\n");
}

void own_handler(int sig) {
    printf("Cool! My own handler <3\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Not enought arguments!");
        return -1;
    }
    procinfo(argv[0]);
    int sig = atoi(argv[2]);
    switch(argv[1][0]) {
        case 'd': {
            break;
        }
        case 'i': {
            signal(sig, ignore_handler);
            break;
        }
        case 'p': {
            signal(sig, own_handler);
            break;
        }
    }
    while (1) pause();
}