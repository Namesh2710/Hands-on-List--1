#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    off_t position;

    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "ABCDEFGHIJ", 10);

    position = lseek(fd, 10, SEEK_CUR);

    if (position == -1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    printf("lseek returned position = %ld\n", position);

    write(fd, "1234567890", 10);

    close(fd);

    return 0;
}
