#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pid2;
    pid = fork();
    if (pid == 0){
        sleep(10);
        printf("Despierto!\n");
    }else{
        pid2 = fork();
        if (pid2 == 0){
            printf("Soy P3 y mi PID es: %d y mi PPID es: %d\n", getpid(), getppid());
        }else{
            wait(NULL);
        }
        wait(NULL);
    }
    exit(0);
}