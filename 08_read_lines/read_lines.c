#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char ch;
    int n;

    fd = open("input.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File contents:\n");

    while ((n = read(fd, &ch, 1)) > 0)
    {
        write(1, &ch, 1);
    }

    close(fd);

    return 0;
}
