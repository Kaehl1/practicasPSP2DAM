#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pidHijo;
    pid = fork();
    if (pid == 0 ) //proceso hijo
    {
        printf("Soy el proceso hijo ... \n");
        printf("Mi PID es: %d y el pid de mi padre es: %d\n", getpid(),getppid());
    }
    else //proceso padre
    {
        pidHijo = wait(NULL);
        printf("Soy el proceso padre\n");
        printf("Mi PID es: %d y el pid de mi padre es: %d\n", getpid(), getppid());
    }
    exit(0);
}