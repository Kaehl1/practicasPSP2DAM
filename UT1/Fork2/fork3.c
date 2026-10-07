#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid,pid2,pid3,pid4,pid5;
    printf("Comienza P1...\n");
    printf("PID: %d\n",getpid());
    pid = fork();
    if (pid == 0)
    {
        printf("Comienza P2...\n");
        printf("PID: %d\n",getpid());
        pid_t pidAbuP1 = getppid();
        pid2 = fork();
        
        if (pid2 == 0)
        {
            printf("Comienza P3...\n");
            printf("PID: %d -> PID Abuelo: %d\n",getpid(),pidAbuP1);
            pid_t pidAbuP2 = getppid();
            pid3 = fork();
            
            if (pid3 == 0)
            {
                printf("Comienza P5...\n");
                printf("PID: %d -> PID Abuelo: %d\n",getpid(),pidAbuP2);
                printf("Termina P5.\n");
            }else{
                wait(NULL);
                printf("Termina P3.\n");
            }
        }else{
            pid_t pidAbuP2 = getppid();
            pid4 = fork();
            
            if (pid4 == 0)
            {
                printf("Comienza P4...\n");
                printf("PID: %d -> PID Abuelo: %d\n",getpid(),pidAbuP1);
                pid5 = fork();
                if (pid5 == 0)
                {
                    printf("Comienza P6...\n");
                    printf("PID: %d -> PID Abuelo: %d\n",getpid(),pidAbuP2);
                    printf("Termina P6.\n");
                }else{
                    wait(NULL);
                    printf("Termina P4.\n");
                }
            }else{
                wait(NULL);
                printf("Termina P2.\n");
            }
        }
    }else{
        wait(NULL);
        printf("Termina P1.\n");
    }
    exit(0);
}