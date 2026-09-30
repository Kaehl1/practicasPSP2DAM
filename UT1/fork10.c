#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pid2;
    pid = fork();
    if (pid == 0){
        int n1;
        printf("P2 - PID: %d\n",getpid());
        for (int i = 1; i < 100; i++){
            n1 = n1+(i+(i+1));
            printf("Sumando %d + %d = %d\n",i,i+1,n1);
        }
    }else{
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0){
            int n1;
            printf("P3 - PID: %d\n",getpid());
            for (int i = 101; i < 200; i++){
                n1 =n1+(i+(i+1));
                printf("Sumando %d + %d = %d\n",i,i+1,n1);
            }
        }else{
            wait(NULL);
            printf("Todos los calculos han finalizado.\n");
        }
    }
    exit(0);
}