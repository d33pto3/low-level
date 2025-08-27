#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// ai generated code
int main()
{
    int fd;
    char buf1[] = "Hello";
    char buf2[] = "World";

    fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write "Hello" at the start
    if (write(fd, buf1, sizeof(buf1) - 1) == -1)
    {
        perror("write buf1");
        exit(EXIT_FAILURE);
    }

    // Move offset 1MB ahead -> creates a hole
    if (lseek(fd, 1024, SEEK_CUR) == -1)
    {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    // Write "World" after the hole
    if (write(fd, buf2, sizeof(buf2) - 1) == -1)
    {
        perror("write buf2");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}