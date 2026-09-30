#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Código del Ejercicio:

void main()
{
    pid_t pid1, pid2;
    printf("AAA \n");
    pid1 = fork();
    if (pid1==0)
    {
        printf("BBB \n");
    }
    else
    {
        pid2 = fork();
        printf("CCC \n");
    }
    exit(0);
}

a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo
que el pid del programa fork8 es el 1000 y los pids se generan de uno en uno en orden creciente.

    P0 "AAA", "CCC"(1000)┬> P1 "BBB"(1001)
                         └> P2 "CCC"(1002)

b) ¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
    La salida que genera el código es:
        AAA
        CCC
        BBB
        CCC
    aunque podria invertirse el orden de los bloques CCC y BBB ya que en el codigo no hay nada que haga que unos se ejecuten
    unos antes que otros, pero siempre se va a ejecutar el bloque AAA en primer lugar ya que se ejecuta antes de ejecutar
    cualquier orden fork(). Asi quedarían las otras dos posibilidades:
        AAA  │  AAA
        BBB  │  CCC
        CCC  │  CCC
        CCC  │  BBB

c) Añade el código necesario para que el orden de ejecución sea tal que los respectivos procesos
padre sean los últimos que se ejecuten.
*/
void main()
{
    pid_t pid1, pid2;
    printf("AAA \n");
    pid1 = fork();
    if (pid1==0)
    {
        printf("BBB \n");
    }
    else
    {
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("CCC \n");
        }else{
            wait(NULL);
            printf("CCC\n");
        }
        
    }
    exit(0);
}