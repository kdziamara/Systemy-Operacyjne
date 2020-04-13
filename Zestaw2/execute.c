#include "procinfo.h"

int main() {
    // bez \n nie przejdziemy do nowej linii, gdy \n to znak nowej linii
    printf("Pierwszy komunikat\n");
    execl("./potomny.x", "execute");
    printf("Drugi komunikat\n"); // drugi komunikat nie zostanie wyświetlony
    return 0;
}