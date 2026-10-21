#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

void main() {
    int fd[2];
    pid_t pid;
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(fd[0]);
        time_t t;
        srand((unsigned)time(&t));
        for (int i = 0; i < 2; i++)
        {
            int numRand = rand()%50;
            write(fd[1],&numRand,sizeof(numRand));
        }
        close(fd[1]);

    } else {
        close(fd[1]);
        int randoms[2];
        for (int i = 0; i < sizeof(randoms); i++)
        {
            int num = 0;
            read(fd[0],&randoms[i],sizeof(num));
        }
        printf("%d + %d = %d\n",randoms[0], randoms[1], randoms[0]+randoms[1]);
        printf("%d - %d = %d\n",randoms[0], randoms[1], randoms[0]-randoms[1]);
        printf("%d * %d = %d\n",randoms[0], randoms[1], randoms[0]*randoms[1]);
        printf("%d / %d = %d\n",randoms[0], randoms[1], randoms[0]/randoms[1]);
        close(fd[0]);
        wait(NULL);
    }
    exit(0);
}