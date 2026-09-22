#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fd_dup, fd_dup2, fd_fcntl;

    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    fd_dup = dup(fd);

    if (fd_dup == -1)
    {
        perror("dup");
        return 1;
    }

    fd_dup2 = dup2(fd, 10);

    if (fd_dup2 == -1)
    {
        perror("dup2");
        return 1;
    }

    fd_fcntl = fcntl(fd, F_DUPFD, 11);

    if (fd_fcntl == -1)
    {
        perror("fcntl");
        return 1;
    }

    printf("Original fd = %d\n", fd);
    printf("dup() fd     = %d\n", fd_dup);
    printf("dup2() fd    = %d\n", fd_dup2);
    printf("fcntl() fd   = %d\n", fd_fcntl);

    write(fd, "Original\n", 9);
    write(fd_dup, "Using dup\n", 10);
    write(fd_dup2, "Using dup2\n", 11);
    write(fd_fcntl, "Using fcntl\n", 12);

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}
