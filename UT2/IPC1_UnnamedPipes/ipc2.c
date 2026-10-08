#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main() {
    int fd[2];
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        close(fd[1]);
        int recibido1,recibido2,recibido3,suma;
        read(fd[0], &recibido1,sizeof(recibido1));
        printf("Recibido %d\n", recibido1);
        read(fd[0], &recibido2,sizeof(recibido2));
        printf("Recibido %d\n", recibido2);
        read(fd[0], &recibido3,sizeof(recibido3));
        printf("Recibido %d\n", recibido3);
        close(fd[0]);

    }else{
        close(fd[0]);
        int num1 = 22;
        int num2 = 11;
        int num3 = 33;
        write(fd[1],&num1,sizeof(num1));
        printf("Enviado %d\n",num1);
        write(fd[1],&num2,sizeof(num2));
        printf("Enviado %d\n",num2);
        write(fd[1],&num3,sizeof(num3));
        printf("Enviado %d\n",num3);
        close(fd[1]);
    }
    exit(0);
}