#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        printf("Daemon started with PID = %d\n", pid);
        return 0;
    }

    if (setsid() == -1)
    {
        perror("setsid");
        return 1;
    }

    chdir(".");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    sleep(10);

    system("./script.sh");

    return 0;
}
