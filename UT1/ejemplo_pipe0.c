#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int n = 10;
    int numeros[n];

    for (int i = 0; i < n; i++)
    {
        numeros[i] = i*3;
    }
    

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        // HIJO: solo lee
        close(fd[1]);

        int recibido;
        for (int i = 0; i < n; i++)
        {
            read(fd[0], &recibido, sizeof(recibido));
            printf("HIJO: He recibido %d\n", recibido);
        }

        close(fd[0]);
    }
    else {
        // PADRE: solo escribe
        close(fd[0]);

        for (int i = 0; i < n; i++)
        {
            write(fd[1], &numeros[i], 4);
            printf("PADRE: He enviado %d\n", numeros[i]);
        }

        close(fd[1]);

        wait(NULL);
    }
}