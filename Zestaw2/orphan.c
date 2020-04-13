#include "procinfo.h"

int main() {
    if (fork() == 0) {
        procinfo("ORPHAN PROCESS");
        sleep(1000);
        return 0;
    }
    return 0;
}