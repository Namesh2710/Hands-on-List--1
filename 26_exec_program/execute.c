#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing hello program...\n");

    execl("./hello", "hello", "Ujjawal", NULL);

    perror("execl");

    return 1;
}
