#include <time.h>
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
        char *recibido;
        read(fd[0],&recibido, sizeof(recibido));
        close(fd[0]);
    }else{
        close(fd[0]);
        time_t hora;
        char *fecha ;
        time(&hora);
        fecha = ctime(&hora);
        write(fd[1], &fecha, sizeof(fecha));
        close(fd[1]);
    }
    exit(0);
}