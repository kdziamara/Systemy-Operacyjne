#include "procinfo.h"

int procinfo(const char* name) {
    printf("%s, UID: %d, GID: %d, PID: %d, PPID: %d, PGID: %d\n", name, getuid(), getgid(), getpid(), getppid(), getpgid(getpid()));
    return 0;
}