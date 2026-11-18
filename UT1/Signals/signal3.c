#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void obtenerHora(char *buffer, size_t tam) {
    time_t ahora = time(NULL);
    struct tm *info = localtime(&ahora);
    strftime(buffer, tam, "%H:%M:%S", info);
}

void manejadorSigint(int sig){
    char hora[20];
    obtenerHora(hora, sizeof(hora));
    FILE *fichero = fopen("salidas.txt", "a");
    if (fichero != NULL) {
        fprintf(fichero,"Señal SIGINT recibida a las %s.\n", hora);
        fclose(fichero);
    }
}

int main() {
    signal(SIGINT, manejadorSigint);

    while (1) {
        pause();
    }

    return 0;
}