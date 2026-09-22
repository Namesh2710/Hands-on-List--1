#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int source, destination;
    char buffer[100];
    int n;

    source = open("file1.txt", O_RDONLY);

    if (source == -1)
    {
        perror("open source");
        return 1;
    }

    destination = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (destination == -1)
    {
        perror("open destination");
        close(source);
        return 1;
    }

    while ((n = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, n);
    }

    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}
