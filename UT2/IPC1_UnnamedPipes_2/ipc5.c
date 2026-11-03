#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main() {
    int pipe1[2],pipe2[2],pipe3[2],pipe4[2];
    pid_t pid,pid2;
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);
    pipe(pipe4);
    pid = fork();
    if (pid == 0)
    {
        //proceso p2 - pipe1 / pipe3
        sleep(30);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        close(pipe3[0]);
        close(pipe4[0]);
        close(pipe4[1]);

        int numeros[2];
        for (int i = 0; i < 2; i++)
        {
            read(pipe1[0],&numeros[i],sizeof(numeros[i]));
        }
        int suma = numeros[0]+numeros[1];
        write(pipe3[1],&suma,sizeof(suma));

        close(pipe1[0]);
        close(pipe3[1]);
    }else
    {
        //proceso p1
        pid2 = fork();
        if (pid2 == 0)
        {
            //proceso p3 - pipe2 / pipe4
            close(pipe1[0]);
            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe3[0]);
            close(pipe3[1]);
            close(pipe4[0]);

            int numeros[2];
            for (int i = 0; i < 2; i++)
            {
                read(pipe2[0],&numeros[i],sizeof(numeros[i]));
            }
            int producto = numeros[0]*numeros[1];
            write(pipe4[1],&producto,sizeof(producto));

            close(pipe2[0]);
            close(pipe4[1]);
        }else
        {
            //proceso p1
            close(pipe1[0]);
            close(pipe2[0]);
            close(pipe3[1]);
            close(pipe4[1]);

            int numeros[2];
            printf("Introduce el primer numero: ");
            scanf("%d",&numeros[0]);
            printf("Introduce el segundo numero: ");
            scanf("%d",&numeros[1]);
            for (int i = 0; i < 2; i++)
            {
                write(pipe1[1],&numeros[i],sizeof(numeros[i]));
                write(pipe2[1],&numeros[i],sizeof(numeros[i]));
            }
            
            int suma = 0;
            int producto = 0;
            read(pipe3[0],&suma,sizeof(suma));
            read(pipe4[0],&producto,sizeof(producto));
            printf("Suma %d + %d = %d\n",numeros[0],numeros[1],suma);
            printf("Producto %d * %d = %d\n",numeros[0],numeros[1],producto);

            wait(NULL);
            wait(NULL);

            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe3[0]);
            close(pipe4[0]);
        }
    }
    exit(0);
}