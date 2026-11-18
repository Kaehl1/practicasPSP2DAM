#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void obtenerFechaHora(char *buffer, size_t tam) {
    time_t ahora = time(NULL);
    struct tm *info = localtime(&ahora);
    strftime(buffer, tam, "%d/%m/%Y %H:%M:%S", info);
}

void manejador(int sig) {
    char fechaHora[30];
    obtenerFechaHora(fechaHora, sizeof(fechaHora));
    printf("Fin del proceso %d: %s\n", getpid(), fechaHora);
    exit(0);
}

int main() {
    signal(SIGINT, manejador);

    char fechaHora[30];
    obtenerFechaHora(fechaHora, sizeof(fechaHora));
    printf("Inicio del proceso %d: %s\n", getpid(), fechaHora);

    while (1) {
        pause();
    }

    return 0;
}