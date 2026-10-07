#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
Estructura a crear:

    P1
    ├──> P2 → espera 5 segundos
    ├──> P3 → espera 2 segundos
    └──> P4 → espera 4 segundos

Cada hijo mostrará cuando comieza y cuando termina.
*/

void main() {
    pid_t pid, pid2, pid3;
    printf("Comienza P1...\n");
    pid = fork();
    if (pid == 0)
    {
        printf("Comienza P2...\n");
        sleep(5);
        printf("Termina P2.\n");
    }else{
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("Comienza P3...\n");
            sleep(2);
            printf("Termina P3.\n");
        }else{
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("Comienza P4...\n");
                sleep(4);
                printf("Termina P4.\n");
            }else{
                waitpid(pid,NULL,0);
                waitpid(pid2,NULL,0);
                waitpid(pid3,NULL,0);
                printf("Termina P1.\n");
            }
        }
    }
    exit(0);
}

/*
a) ¿Podemos asegurar ahora que proceso terminará primero?
    
    Técnicamente no se puede asegurar el proceso que terminará primero ya que la orden sleep() no aegura que cuando termina
    ese proceso pase a ejecucion si no que el proceso pasa a la cola de preparados y es el procesador el que determina cuando
    pasa a ejecutarse cada proceso, aun que en programas tan cortos sea practicamente seguro determinar un orden con sleep().

b) Si eliminamos la instrucción sleep() ¿cual seria el orden de terminación?

    Si eliminamos los sleep() al ser un programa tan pequeño probablemente el orden de terminación sea: 
    P2 > P3 > P4 > P1. Aunque en principio es indeterminado, podemos asegurar que P1 siempre será el ultimo proceso en terminar
    debido a las llamadas bloqueantes waitpid() que le obligan a esperar a la finalizacion de sus 3 hijos antes de finalizar él.
*/