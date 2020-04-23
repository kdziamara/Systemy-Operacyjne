#include "procinfo.h"

void handler(int sig) {
    printf("Signal catched by child!\n");
}

void lider_handler(int sig) {

}

int main(int argc, char *argv[]) {
    int children = 4;
    int child = fork();
    if (child) {
        // Proces macierzysty
        procinfo("macierzysty");

        int times = 0;
        do {
            kill(0, 0);
            if (times > 5) return -1;
            times++;
            sleep(1);
        } while (errno == ESRCH);

        int groupid = getpgid(child);

        kill(-groupid, SIGUSR1);
        if (waitpid(child, NULL, 0) == -1) {
            printf("ERROR\n");
        }        
    } else {
        // Proces potomny
        setpgid(0, 0);
        procinfo("potomny-lider");
        for (int i = 0; i < children; i++) {
            if (fork() == 0) {
                procinfo("potomne");
                signal(SIGUSR1, handler);
                pause();
                return rand();
            }
        }
        signal(SIGUSR1, (void*)lider_handler);
        for (int i = 0; i < children; i++) {
            int status;
            if (waitpid(-1, &status, 0) == -1) {
                printf("ERROR\n");
            }
            if(WIFEXITED(status)) {
                printf("Child process returned normally with status: %d\n", status);        
            }
        }
        sleep(1);
    }
    return 0;
}