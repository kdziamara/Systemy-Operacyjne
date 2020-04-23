#include "procinfo.h"

void handler(int sig) {
    printf("Signal cached!");
    exit(12);
}

int main(int argc, char *argv[]) {
    procinfo(argv[0]);
    int child = fork();
    int children = 4;
    if (child) {
        // Proces macierzysty
        int groupid = getpgid(child);
        kill(-groupid, 0);
        if (errno == ESRCH) {
            return -1;
        }
        sleep(1);
        kill(-groupid, SIGINT);
        waitpid(child, NULL, 0);
    } else {
        // Proces potomny
        setpgid(0, 0);
        procinfo("potomny-lider");
        for (int i = 0; i < children; i++) {
            if (fork() == 0) {
                procinfo("potomne");
                signal(SIGINT, handler);
                pause();
            }
        }
        signal(SIGINT, (void*)NULL);
        for (int i = 0; i < children; i++) {
            int status;
            wait(&status);
            printf("%d\n", status);
        }
    }
    return 0;
}