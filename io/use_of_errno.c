#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("nonexistent.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("open() failed!\n");
        printf("errno: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
    }

    return 0;
}