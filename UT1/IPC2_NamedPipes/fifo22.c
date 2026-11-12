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
    const char *fifo = "PIPE2";
    int fd = open(fifo, O_RDONLY);
    int num = 0;
    unsigned long long factorial = 1;
    if (fd == -1)
    {
        printf("Error al abrir FIFO\n");
        exit(EXIT_FAILURE);
    }
    if (read(fd,&num, sizeof(num)) == -1)
    {
        printf("Error al leer del pipe.\n");
    }else{
        printf("Numero recibido.\n");
    }
    close(fd);
    factorial = calcularFactorial(num);
    fd = open(fifo, O_WRONLY);
    if (fd == -1)
    {
        printf("Error al abrir FIFO\n");
        exit(EXIT_FAILURE);
    }

    if (write(fd,&factorial,sizeof(factorial)) == -1)
    {
        printf("Error al escribir en el pipe.\n");
    }else
    {
        printf("Factorial enviado.\n");
    }
    return 0;
}