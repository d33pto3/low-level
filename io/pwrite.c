#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int fd = open("ex.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    const char *msg = "We will rock you";

    // Write 17 bytes starting from 0
    ssize_t n = pwrite(fd, msg, strlen(msg), 0);

    if (n == -1)
    {
        perror("pwrite");
        close(fd);
        exit(1);
    }

    printf("Wrote %zd bytes at offset 0\n", n);

    // Check current offset
    off_t pos = lseek(fd, 0, SEEK_CUR);
    printf("Current file offset is still: %ld\n", (long)pos);

    close(fd);
    return 0;
}