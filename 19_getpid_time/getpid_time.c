#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc()
{
    unsigned int lo, hi;

    __asm__ volatile (
        "rdtsc"
        : "=a"(lo), "=d"(hi)
    );

    return ((unsigned long long)hi << 32) | lo;
}

int main()
{
    unsigned long long start, end;
    pid_t pid;

    start = rdtsc();

    pid = getpid();

    end = rdtsc();

    printf("PID = %d\n", pid);
    printf("Timestamp before getpid = %llu\n", start);
    printf("Timestamp after getpid  = %llu\n", end);
    printf("Cycles taken by getpid  = %llu\n", end - start);

    return 0;
}
