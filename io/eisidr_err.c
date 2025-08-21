#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = open("../io", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
    }

    return 0;
}