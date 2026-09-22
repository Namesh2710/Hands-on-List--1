#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat st;

    if (stat("test.txt", &st) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode number       : %ld\n", st.st_ino);
    printf("Hard links         : %ld\n", st.st_nlink);
    printf("UID                : %d\n", st.st_uid);
    printf("GID                : %d\n", st.st_gid);
    printf("File size          : %ld bytes\n", st.st_size);
    printf("Block size         : %ld bytes\n", st.st_blksize);
    printf("Blocks             : %ld\n", st.st_blocks);

    printf("Last access        : %s", ctime(&st.st_atime));
    printf("Last modification  : %s", ctime(&st.st_mtime));
    printf("Last status change : %s", ctime(&st.st_ctime));

    return 0;
}
