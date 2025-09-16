#include <stdio.h>
#include <unistd.h>
int main()
{
    __pid_t pid = getpid();
    __pid_t ppid = getppid();

    printf("Process ID is: %d\n", pid);
    printf("Parent Process ID of Process ID %d is: %d\n", pid, ppid);

    return 0;
}