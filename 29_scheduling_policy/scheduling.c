#include <stdio.h>
#include <unistd.h>
#include <sched.h>

void print_policy(int policy)
{
    if (policy == SCHED_OTHER)
        printf("Current policy: SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("Current policy: SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("Current policy: SCHED_RR\n");
    else
        printf("Unknown scheduling policy\n");
}

int main()
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1)
    {
        perror("sched_getscheduler");
        return 1;
    }

    print_policy(policy);

    param.sched_priority = 10;

    printf("Trying to set SCHED_FIFO...\n");

    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
    {
        perror("SCHED_FIFO");
    }
    else
    {
        printf("SCHED_FIFO set successfully.\n");
        policy = sched_getscheduler(0);
        print_policy(policy);
    }

    printf("Trying to set SCHED_RR...\n");

    if (sched_setscheduler(0, SCHED_RR, &param) == -1)
    {
        perror("SCHED_RR");
    }
    else
    {
        printf("SCHED_RR set successfully.\n");
        policy = sched_getscheduler(0);
        print_policy(policy);
    }

    return 0;
}
