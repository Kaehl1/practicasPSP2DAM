#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void main() {
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        close(fd[1]);
        char recibido[100];
        read(fd[0],recibido, sizeof(recibido));
        printf("Fecha recibida: %s\n", recibido);
        close(fd[0]);
    }else{
        close(fd[0]);
        time_t hora;
        char *fecha ;
        time(&hora);
        fecha = ctime(&hora);
        write(fd[1], fecha, strlen(fecha)+1);
        printf("Fecha enviada: %s\n", fecha);
        close(fd[1]);
    }
    exit(0);
}