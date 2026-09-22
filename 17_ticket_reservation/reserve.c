#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int ticket;
    struct flock lock;
    char buffer[20];

    fd = open("ticket.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire write lock...\n");

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);

    int n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';

    sscanf(buffer, "%d", &ticket);

    ticket++;

    lseek(fd, 0, SEEK_SET);
    ftruncate(fd, 0);

    int len = snprintf(buffer, sizeof(buffer), "%d\n", ticket);
    write(fd, buffer, len);

    printf("New ticket number = %d\n", ticket);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);

    return 0;
}
