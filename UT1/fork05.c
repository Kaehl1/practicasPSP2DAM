#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid,pid2,pid3;
    pid = fork();
    if (pid == 0) {
        pid2 = fork();
        if (pid2 == 0) {
            printf("Soy P3 - PID: %d - PPID: %d\n",getpid(),getppid());
        }else {
            wait(NULL);
            printf("Soy P2 - PID: %d - PPID: %d\n", getpid(),getppid());
        }
    }else {
        wait(NULL);
        printf("Soy P1 - PID: %d - PID HIJO: %d\n",getpid(),pid);
    }
    exit(0);
}