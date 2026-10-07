#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 

Codigo del Ejercicio:

void main()
{
    printf("CCC \n");
    if (fork()!=0)
    {
        printf("AAA \n");

    } else printf("BBB \n");

    exit(0);
}

------------------------------------------------

a)Dibuja un gráfico de la jerarquia de procesos que genera la ejecucion de este código, suponiendo que el PID del programa fork7
es el 1000 y los PIDs se generan de uno en uno en orden creciente.

    P0 (PID: 1000) -> P1 (PID: 1001)

b)¿Que salida genera este código?¿Podria producirse otra salida? Justifica la respuesta.

    La salida que se genera es:
        CCC
        AAA
        BBB
    Pero como el procesador va ejecutando los procesos aleatoriamente segun el tiempo asignado de procesamiento a cada uno, podria
    generarse otra salida como:
        CCC
        BBB
        AAA
    aunque al ser un programa tan corto lo que sale casi siempre es la primera opcion.

c) Modificar el código para que la salida por pantalla sea:
    
    CCC
    BBB
    AAA
*/

void main(){
    printf("CCC \n");
    if (fork()!=0){
        wait(NULL);
        printf("AAA \n");
    } else{
        printf("BBB \n");
    }
    exit(0);
}