#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pid2, pid3;
    printf("Comienza P1...\n");
    pid = fork();
    if (pid == 0)
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("Comienza P4...\n");
                pid_t suma4 = getpid()+getppid();
                printf("P4 -> PID: %d + PPID: %d = %d\n",getpid(),getppid(), suma4);
                printf("Termina P4.\n");
            }else{
                printf("Comienza P3...\n");
                pid_t suma3 = getpid()+getppid();
                printf("P3 -> PID: %d + PPID: %d = %d\n",getpid(),getppid(), suma3);
                wait(NULL);
                printf("Termina P3.\n");
            } 
        }else{
            printf("Comienza P2...\n");
            pid_t suma2 = getpid()+getppid();
            printf("P2 -> PID: %d + PPID: %d = %d\n",getpid(),getppid(), suma2);
            wait(NULL);
            printf("Termina P2.\n");
        }
    }else{
        pid_t suma1 = getpid()+getppid();
        printf("P1 -> PID: %d + PPID: %d = %d\n",getpid(),getppid(), suma1);
        wait(NULL);
        printf("Termina P1.\n");
    }
    exit(0);
}