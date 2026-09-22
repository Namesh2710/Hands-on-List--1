#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2, fd3, fd4, fd5;

    fd1 = open("file1.txt", O_CREAT | O_RDWR, 0644);
    fd2 = open("file2.txt", O_CREAT | O_RDWR, 0644);
    fd3 = open("file3.txt", O_CREAT | O_RDWR, 0644);
    fd4 = open("file4.txt", O_CREAT | O_RDWR, 0644);
    fd5 = open("file5.txt", O_CREAT | O_RDWR, 0644);

    printf("FDs: %d %d %d %d %d\n", fd1, fd2, fd3, fd4, fd5);

    while (1)
    {
        sleep(5);
    }

    return 0;
}
