#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid,pid2,pid3,pid4,pid5,acumulado;
    printf("Comienza P1...\n");
    acumulado = getpid();
    pid = fork();
    if (pid == 0){
        printf("Comienza P2...\n");
        pid2 = fork();
        if (pid2 == 0){
            printf("Comienza P5...\n");
            pid5 = fork();
            if (pid5 == 0){
                if (getpid()%2 == 0)
                {
                    acumulado = acumulado + 10;
                    printf("%d\n",acumulado);
                }else{
                    acumulado = acumulado -100;
                    printf("%d\n",acumulado);
                }
            }
        }else{
            if (getpid()%2 == 0){
                acumulado = acumulado + 10;
                printf("%d\n",acumulado);
            }else{
                acumulado = acumulado -100;
                printf("%d\n",acumulado);
            }
        }
    }else{
        pid3 = fork();
        if(pid3 == 0){
            printf("Comienza P3...\n");
            pid4 = fork();
            if(pid4 == 0){
                printf("Comienza P4...\n");
                if (getpid()%2 == 0){
                    acumulado = acumulado + 10;
                    printf("%d\n",acumulado);
                }else{
                    acumulado = acumulado -100;
                    printf("%d\n",acumulado);
                }
            }else{
                if (getpid()%2 == 0)
                {
                    acumulado = acumulado + 10;
                    printf("%d\n",acumulado);
                }else{
                    acumulado = acumulado -100;
                    printf("%d\n",acumulado);
                }
            }
        }else{
            if (getpid()%2 == 0)
            {
                acumulado = acumulado + 10;
                printf("%d\n",acumulado);
            }else{
                acumulado = acumulado -100;
                printf("%d\n",acumulado);
            }
        }
    }
    exit(0);
}