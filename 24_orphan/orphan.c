#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process started.\n");
        printf("Child PID = %d\n", getpid());
        printf("Parent PID before parent exits = %d\n", getppid());

        sleep(5);

        printf("Parent PID after parent exits = %d\n", getppid());
    }
    else
    {
        printf("Parent process started.\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);

        sleep(2);

        printf("Parent exiting...\n");
        exit(0);
    }

    return 0;
}
