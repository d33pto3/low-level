#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <errno.h>
#include <string.h>

int main()
{
    // Open file for reading
    int fd = open("example.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("exit");
        return 1;
    }

    // Two buffers to scatter data into
    char buf1[10];
    char buf2[20];

    // iovec array describes where data should go
    struct iovec iov[2];
    iov[0].iov_base = buf1; // first buffer
    iov[0].iov_len = sizeof(buf1);

    iov[0].iov_base = buf1; // second buffer
    iov[0].iov_len = sizeof(buf1);

    // Perform scatter read
    ssize_t nread = readv(fd, iov, 2);
    if (nread == -1)
    {
        perror("readv");
        close(fd);
        return 1;
    }

    printf("Total bytes read %zd\n", nread);

    // Null terminate for printing
    buf1[sizeof(buf1) - 1] = '\0';
    buf2[sizeof(buf2) - 1] = '\0';

    printf("Buffer 1: '%s'\n", buf1);
    printf("Buffer 2: '%s'\n", buf2);

    close(fd);
    return 0;
}