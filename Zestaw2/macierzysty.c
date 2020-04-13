#include "procinfo.h"

int main(int argc, char *argv[]) {
    strncpy(argv[0], "macierzysty\0", 7);
    procinfo(argv[0]);

    int gen_nr = 1;
    int waiting = 0;

    for (int i = 0; i < 3; i++) {
        int child = fork();
        if (child == 0) {
            char name[40];
            // wyświetlanie generacji
            sprintf(name, "gen: %d", gen_nr++);
            procinfo(name);
            execl("./potomny.x", name);
        } else {
            waiting++;
        }
    }

    for (int i = 0; i < waiting; i++) {
        wait(NULL);
    }
    return 0;
}