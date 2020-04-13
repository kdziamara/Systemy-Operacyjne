#include "procinfo.h"

int main() {
    if (fork() == 0) {
        procinfo("ZOMBIE PROCESS");
        return 0;
    }
    sleep(1000);
    wait(NULL);
    return 0;
}