#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    printf("Inicio\n");
    pid_t pid = fork();
    printf("Después del fork\n");
    if (pid == 0) {
        printf("Soy el hijo\n");
    } else {
        printf("Soy el padre\n");
    }
    printf("Fin\n");
}

/*
¿Cuantos procesos existen?
    Existen 2 procesos ya que al mandar a ejecucion nuestro programa se crea un proceso y
    despues en la linea 9 ejecutamos la funcion fork() que lo que hace es crear un proceso hijo.

¿Que instrucciones ejecuta cada uno?
    El proceso padre comienza pintando en la terminal "Inicio" despues crea el proceso hijo y pinta
    de nuevo "Despues del fork" en la terminal. Mas adelante entra en el else y pinta "Soy el padre" y termina.
    El proceso hijo en cambio ejecuta solamente desde la linea 10 pintando "Despues del fork" para entrar en el if y pintar
    "Soy el hijo". Cuando sale del if pinta "Fin" y termina.

¿Cuantas veces sale cada mensaje y que partes de la salida pueden aparecer en distinto orden?
    "Inicio" sale solamente una vez ya que sucede solamente en el proceso padre justo antes del fork.
    "Despues del fork" aparece siempre 2 veces ya que al suceder despues del fork lo pintan ambos procesos, padre e hijo.
    "Soy el hijo" aparece solamente 1 vez ya que se ejecuta condicionalmente si es el proceso hijo.
    "Soy el padre" al igual que el anterior aparece solamente una vez ya que se ejecuta condicionalmente si es el proceso padre.
    "Fin" aparece 2 veces ya que se ejecuta fuera de los condicionales y por lo tanto lo ejecutan ambos procesos.
    Los mensajes que pueden aparecer en distinto orden son "Soy el padre" y "Soy el hijo" ya que los procesos se ejecutan por
    el procesador de forma aleatoria.
*/