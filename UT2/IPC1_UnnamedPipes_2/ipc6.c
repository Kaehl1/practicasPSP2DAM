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
        //proceso p2
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        close(pipe3[1]);
        close(pipe4[0]);
        close(pipe4[1]);

        int notas[10];
        int suma = 0, masAlta = 0;
        read(pipe3[0],&notas,sizeof(notas));
        for (int i = 0; i < 10; i++)
        {
            suma += notas[i];
            if (masAlta < notas[i])
            {
                masAlta = notas[i];
            }
            
        }
        int media = suma/10;
        int resultados[2] = {media, masAlta};
        write(pipe1[1],resultados,sizeof(resultados));

        close(pipe1[1]);
        close(pipe3[0]);
    }else
    {
        //proceso p1
        pid2 = fork();
        if (pid2 == 0)
        {
            //proceso p3
            close(pipe1[0]);
            close(pipe1[1]);
            close(pipe2[0]);
            close(pipe3[0]);
            close(pipe3[1]);
            close(pipe4[1]);

            int notas[10], aprobados = 0, suspensos = 0;
            read(pipe4[0],&notas,sizeof(notas));

            for (int i = 0; i < 10; i++)
            {
                if (notas[i]>=5)
                {
                    aprobados++;
                }
                if (notas[i]<5)
                {
                    suspensos++;
                }
            }
            int resultados[2] = {aprobados,suspensos};
            write(pipe2[1],resultados,sizeof(resultados));

            close(pipe2[1]);
            close(pipe4[0]);
        }else
        {
            //proceso p1
            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe3[0]);
            close(pipe4[0]);

            int notas[10];
            int count = 0;
            int entrada;
            for (int i = 0; i < 10; i++) {
                do {
                    printf("Escribe la nota numero %d (0-10): ", i + 1);
                    scanf("%d", &notas[i]);
                } while (notas[i] < 0 || notas[i] > 10);
            }

            write(pipe3[1],notas, sizeof(notas));
            write(pipe4[1],notas, sizeof(notas));
            int resultadosP2[2],resultadosP3[2];
            read(pipe1[0],resultadosP2,sizeof(resultadosP2));
            read(pipe2[0],resultadosP3,sizeof(resultadosP3));
            printf("Nota media: %d\n",resultadosP2[0]);
            printf("Nota maxima: %d\n",resultadosP2[1]);
            printf("Numero de alumnos aprobados: %d\n",resultadosP3[0]);
            printf("Numero de alumnos suspensos: %d\n",resultadosP3[1]);
            
            wait(NULL);
            wait(NULL);

            close(pipe1[0]);
            close(pipe2[0]);
            close(pipe3[1]);
            close(pipe4[1]);
        }
    }
    exit(0);
}