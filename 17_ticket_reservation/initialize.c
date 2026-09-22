#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("ticket.txt", "w");

    if (fp == NULL)
    {
        perror("fopen");
        return 1;
    }

    fprintf(fp, "1000\n");

    fclose(fp);

    printf("Ticket number initialized to 1000.\n");

    return 0;
}
