#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int fd = open("ex.txt", O_RDONLY | O_CREAT);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    char buf[20];

    // Read 10 bytes starting from offset 5
    ssize_t n = pread(fd, buf, 10, 5);
    if (n == -1)
    {
        perror("pread");
        close(fd);
        exit(1);
    }

    buf[n] = '\0'; // null-terminate
    printf("Read from offset 5: '%s'\n", buf);

    // Check current offset
    off_t pos = lseek(fd, 0, SEEK_CUR);
    printf("Current file offset is still: %ld\n", (long)pos);

    close(fd);
    return 0;
}