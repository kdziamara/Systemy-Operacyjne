#include "procinfo.h"
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Not enought arguments!\n");
        return -1;
    }
    procinfo(argv[0]);
    int child = fork();
    if (child) {
        // Proces macierzysty
        while (1) {
            sleep(1);
            kill(child, 0);
            if (errno == ESRCH) {
                return -1;
            }
            kill(child, atoi(argv[2]));
        }
    } else {
        // Proces potomny
        execl("./obsluga.x", "./obsluga.x", argv[1], argv[2], (char*)0);
    }
    return 0;
}