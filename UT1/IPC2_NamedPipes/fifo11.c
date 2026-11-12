#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int numeroRandom (){
    time_t t;
    srand((unsigned)time(&t));
    int numRand = rand()%10;
    return numRand;
}

int main() {
    const char *fifo = "FIFO1";
    const char *fifo2 = "FIFO2";
    int numero = numeroRandom();
    unsigned long long factorial=1;
    mkfifo(fifo,0666);
    int fd = open(fifo, O_WRONLY);
    if (fd == -1){
        printf("Error al abrir FIFO de escritura.\n");
        exit(EXIT_FAILURE);
    }
    if (write(fd, &numero, sizeof(numero))==-1)
    {
        printf("Error al escribir en el pipe.\n");
    }else{
        printf("Numero %d enviado.\n",numero);
    }
    int fd2 = open(fifo2, O_RDONLY);
    if (fd2 == -1)
    {
        printf("Error al abrir FIFO de lectura.");
        exit(EXIT_FAILURE);
    }
    if (read(fd2,&factorial,sizeof(factorial))==-1)
    {
        printf("Error al leer del pipe FIFO2.\n");
    }else{
        printf("Factorial de %d = %llu\n",numero,factorial);
    }

    unlink(fifo);
    return 0;
}