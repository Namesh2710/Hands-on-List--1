#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    int priority;

    priority = getpriority(PRIO_PROCESS, 0);

    if (priority == -1)
    {
        perror("getpriority");
        return 1;
    }

    printf("Process ID = %d\n", getpid());
    printf("Process priority (nice value) = %d\n", priority);

    return 0;
}
