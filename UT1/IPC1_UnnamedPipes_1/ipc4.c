#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

void main() {
    int pipe1[2],pipe2[2];
    pid_t pid;
    pipe(pipe1);
    pipe(pipe2);
    pid = fork();
    if (pid == 0){
        close(pipe1[1]);
        close(pipe2[0]);
        
        int num = 0;
        read(pipe1[0],&num,sizeof(num));
        unsigned long long resultado = 1;
        for (int i = 1; i <= num; i++)
        {
            resultado*= i;
        }
        write(pipe2[1],&resultado,sizeof(resultado));

        close(pipe2[1]);
        close(pipe1[0]);
    }else{
        close(pipe1[0]);
        close(pipe2[1]);

        time_t t;
        srand((unsigned)time(&t));
        int numRand = rand()%10;
        write(pipe1[1],&numRand,sizeof(numRand));
        printf("El proceso padre genera el numero %d en el pipe1.\n",numRand);
        unsigned long long factorial = 1;
        read(pipe2[0],&factorial,sizeof(factorial));
        printf("El factorial calculado por el proceso hijo %d! = %llu\n",numRand,factorial);
        wait(NULL);
        close(pipe2[0]);
        close(pipe1[1]);
    }
    exit(0);
}