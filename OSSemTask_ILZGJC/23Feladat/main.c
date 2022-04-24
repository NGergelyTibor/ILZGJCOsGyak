#include <stdio.h>
#include <stdlib.h>
#include "sys/types.h"
#include "sys/wait.h"
#include "stdbool.h"
#include "string.h"
int main() {
    char input[20];
    int status;
    bool exit = false;
    while (!exit) {

        printf("Kerem adjon meg egy unix commandot!\n");
        scanf("%s", &input);
        if(strcmp(input,"quit") == 0){
            exit = true;
        }
        if ((status = system(input)) < 0)
            perror("system() error");
        if (WIFEXITED(status))
            printf("Normális befejeződés, visszaadott érték= %d\n", WEXITSTATUS(status));
    }
}
