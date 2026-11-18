#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int tiempoTranscurrido = 0;

void manejadorAlarma(int numSenal) {
    tiempoTranscurrido += 5;
    printf("Han transcurrido %d segundos\n", tiempoTranscurrido);
    alarm(5);
}

int main() {
    signal(SIGALRM, manejadorAlarma);
    alarm(5);

    while (1) {
        pause();
    }

    return 0;
}