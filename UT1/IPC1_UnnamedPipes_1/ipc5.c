#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main() {
    int pipe1[2],pipe2[2];
    pid_t pid;
    pipe(pipe1);
    pipe(pipe2);
    pid = fork();
    if (pid == 0){
        close(pipe1[0]);
        close(pipe2[1]);

        int entrada;
        do
        {
            printf("Introduce los digitos del NIF: ");
            scanf("%d", &entrada);
        } while (entrada < 0 || entrada > 99999999);
        write(pipe1[1],&entrada, sizeof(entrada));
        char res;
        read(pipe2[0],&res,sizeof(res));
        printf("%c\n",res);

        close(pipe2[0]);
        close(pipe1[1]);
    }else{
        close(pipe1[1]);
        close(pipe2[0]);
        
        int nif = 0;
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        read(pipe1[0],&nif,sizeof(nif));
        nif %= 23;
        char res = letra[nif];
        write(pipe2[1], &res, sizeof(res));

        close(pipe2[1]);
        close(pipe1[0]);
        wait(NULL);
    }
    exit(0);
}