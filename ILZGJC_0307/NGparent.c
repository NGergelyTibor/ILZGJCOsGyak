#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (void) {
    pid_t pid;

    if ((pid = fork()) < 0){
        perror("process hiba");
    }
    else if (pid == 0){
        if(execl("./NGchild", "child", (char *) NULL) < 0){
            perror("execl hiba");
        }
    }
    if (waitpid(pid, NULL, 0) < 0){
        perror("wait hiba");
    }
    return 0;
}
