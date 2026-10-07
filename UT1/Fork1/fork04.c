#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pidP3;
    pid = fork();
    if (pid == 0) {
        sleep(3);
        printf("P2 - PID: %d - PPID: %d\n",getpid(),getppid());
    }else {
        pidP3 = fork();
        if (pidP3 == 0) {
            sleep(1);
            printf("P3 - PID: %d - PPID: %d\n",getpid(),getppid());
        }else {
            printf("P1 - PID: %d - PPID: %d\n",getpid(),getppid());
            pidHijo1 = wait(NULL);
            pidHijo2 = wait(NULL);
            printf("Todos mis hijos han terminado.\n");
        }
    }
    exit(0);
}