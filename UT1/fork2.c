#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid, pidHijo;
    pid = fork();
    if (pid == 0 ){ //proceso hijo
        printf("Me llamo Brian Velarde.\n");
    }
    else { //proceso padre
        pidHijo = wait(NULL);
        printf("El PID de mi hijo es: %d. Mi PID propio es: %d\n", pid,getpid());
    }
    exit(0);
}