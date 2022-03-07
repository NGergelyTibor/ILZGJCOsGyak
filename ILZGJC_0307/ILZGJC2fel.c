#include <stdio.h>
#include <stdlib.h>
#include "sys/types.h"
#include "sys/wait.h"
int main() {
    char input[20];
    int status;
    printf("Kerem adjon meg egy unix commandot!\n");
    scanf("%s", &input);
    if((status = system(input)) < 0)
        perror("system() error");
    if(WIFEXITED(status))
        printf("Normális befejeződés, visszaadott érték= %d\n", WEXITSTATUS(status));
    return 0;
}
