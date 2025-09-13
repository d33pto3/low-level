#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // code
    int fd = open("ex.txt", O_WRONLY | O_APPEND, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        perror("lseek");
        return 1;
    }

    const char *msg = "This should go at start";

    if (write(fd, msg, strlen(msg)) == -1)
    {
        perror("write");
        return 1;
    }

    close(fd);

    return 0;
}