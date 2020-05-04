#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    char *name = "fifo\0";
	mkfifo(name, 0600);

    if (fork() == 0) {
        execl("./konsument.x", name, (char *)0);
        return 0;
    }
    if (fork() == 0) {
        execl("./producent.x", name, (char *)0);
        return 0;
    }

    wait(NULL);
    wait(NULL);

    unlink(name);
    printf("Copying done!\n");
    return 0;
}