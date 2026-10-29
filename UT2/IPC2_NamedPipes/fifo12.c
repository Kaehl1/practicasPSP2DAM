#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

unsigned long long calcularFactorial(int num){
    unsigned long long resultado = 1;
    for (int i = 1; i <= num; i++)
    {
        resultado*= i;
    }
    return resultado;
}

int main() {
    const char *fifo = "FIFO1";
    const char *fifo2 = "FIFO2";
    mkfifo(fifo2,0666);
    int fd = open(fifo, O_RDONLY);
    int numero;
    if (fd == -1)
    {
        printf("Error al abrir FIFO1 de lectura.\n");
        exit(EXIT_FAILURE);
    }
    if (read(fd,&numero,sizeof(numero))==-1)
    {
        printf("Error al leer el numero de FIFO1.\n");
    }else
    {
        printf("Numero leido: %d\n",numero);
    }
    unsigned long long factorial = calcularFactorial(numero);
    int fd2 = open(fifo2, O_WRONLY);
    if (fd2 == -1)
    {
        printf("Error al abrir FIFO2 de escritura.\n");
        exit(EXIT_FAILURE);
    }
    if (write(fd2,&factorial,sizeof(factorial))==-1)
    {
        printf("Error al escribir en el pipe FIFO2.\n");
    }else{
        printf("Factorial enviado: %llu\n",factorial);
    }
    unlink(fifo2);
    return 0;
}