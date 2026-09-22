#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct record
{
    int id;
    char name[20];
};

int main()
{
    int fd;
    struct record records[3] = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    struct record rec;
    struct flock lock;
    int record_no;

    fd = open("records.dat", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, records, sizeof(records));

    printf("Enter record number to access (1-3): ");
    scanf("%d", &record_no);

    if (record_no < 1 || record_no > 3)
    {
        printf("Invalid record number.\n");
        close(fd);
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (record_no - 1) * sizeof(struct record);
    lock.l_len = sizeof(struct record);

    printf("Trying to lock record %d...\n", record_no);

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Record %d locked.\n", record_no);

    lseek(fd, lock.l_start, SEEK_SET);
    read(fd, &rec, sizeof(rec));

    printf("ID   : %d\n", rec.id);
    printf("Name : %s\n", rec.name);

    printf("Enter new name: ");
    scanf("%19s", rec.name);

    lseek(fd, lock.l_start, SEEK_SET);
    write(fd, &rec, sizeof(rec));

    printf("Record updated successfully.\n");

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Record %d unlocked.\n", record_no);

    close(fd);

    return 0;
}
