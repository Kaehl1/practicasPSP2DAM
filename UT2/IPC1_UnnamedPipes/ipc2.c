#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main() {
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        sleep(2);
        close(fd[1]);
        char buffer[100];
        int suma = 0;

        read(fd[0], buffer, sizeof(buffer));
        while (strcmp(buffer, "+") != 0) {
            printf("Numero a sumar: %s\n", buffer);
            suma += atoi(buffer);
            read(fd[0], buffer, sizeof(buffer));
        }
        printf("Recibido carácter +\n");
        printf("La suma total es igual a: %d\n", suma);
        close(fd[0]);

    } else {
        close(fd[0]);
        char entrada[32];
        do {
            scanf("%s", entrada);
            write(fd[1], entrada, strlen(entrada) + 1);
        } while (strcmp(entrada, "+") != 0);
        close(fd[1]);
        wait(NULL);
    }
    exit(0);
}