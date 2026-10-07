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
        printf("Comienza P2...\n");
        pid_t p2 = getpid();
        if (p2%2 == 0)
        {
            printf("P2 -> PID: %d PPID: %d\n",p2,getppid());
        }else{
            printf("P2 -> PID: %d\n",p2);
        }
        printf("Termina P2.\n");
    }else{
        pid2 = fork();
        if (pid2 == 0)
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("Comienza P4...\n");
                pid_t p4 = getpid();
                if (p4%2 == 0)
                {
                    printf("P4 -> PID: %d PPID: %d\n",p4,getppid());
                }else{
                    printf("P4 -> PID: %d\n",p4);
                }
                printf("Termina P4.\n");
            }else{
                printf("Comienza P3...\n");
                pid_t p3 = getpid();
                if (p3%2 == 0)
                {
                    printf("P3 -> PID: %d PPID: %d\n",p3,getppid());
                }else{
                    printf("P3 -> PID: %d\n",p3);
                }
                wait(NULL);
                printf("Termina P3.\n");
            }
        }else{
            wait(NULL);
            wait(NULL);
            printf("Termina P1.\n");
        }
        
    }
    exit(0);
}
/*
a) ¿Cual será el orden de ejecucion de los procesos?¿Será siempre el mismo?Justifica tu respuesta.
    Debido a como he estructurado las ordenes wait(); y lo corto que es el programa, siempre va a terminar P2 primero,
    segundo terminará P4 seguido de P3 y por ultimo P1.
*/