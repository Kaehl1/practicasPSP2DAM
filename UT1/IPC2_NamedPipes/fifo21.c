#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int numeroRandom (){
    time_t t;
    srand((unsigned)time(&t));
    int numRand = rand()%11;
    return numRand;
}

int main() {
    const char *fifo = "PIPE2";
    int num = numeroRandom();
    unsigned long long factorial = 1;
    mkfifo(fifo,0666);
    int fd = open(fifo, O_WRONLY);
    if (fd == -1)
    {
        printf("Error al abrir FIFO\n");
        exit(EXIT_FAILURE);
    }
    if (write(fd,&num, sizeof(num)) == -1)
    {
        printf("Error al escribir en el pipe.\n");
    }else{
        printf("Numero %d enviado.\n", num);
    }
    close(fd);
    fd = open(fifo, O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir FIFO\n");
        exit(EXIT_FAILURE);
    }
    if (read(fd,&factorial,sizeof(factorial)) == -1)
    {
        printf("Error al leer del pipe.\n");
    }else
    {
        printf("Factorial de %d = %llu\n",num,factorial);
    }
    unlink(fifo);
    return 0;
}