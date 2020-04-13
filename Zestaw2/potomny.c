#include "procinfo.h"

int main(int argc, char *argv[]) {
    if (argc < 1) {
        procinfo("POTOMNY - noname");
    } else {
        char name[60];
        sprintf(name, "POTOMNY - %s", argv[0]);
        procinfo(name);
    }
    return 0;
}