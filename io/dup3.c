#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// int dup3(int oldfd, int newfd, int flags);
int main()
{
    // Open a file for writing(create if doesn't exist)
    int fd = open("outpput.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    // Duplicate fd into descriptor 1 (stdout) using dup3
    // The O_CLOEXEC flag ensures that if this process calls exec(),
    // the new program will not inherit fd 1.
    if (dup3(fd, 1, __O_CLOEXEC) == -1)
    {
        perror("dup3");
        close(fd);
        exit(1);
    }

    // Now, anything written to stdout (fd 1) will go to output.txt
    printf("Hello, this goes to file instead of the terminal!\n");

    // Clean up
    close(fd); // optional: stdout still works because it's duplicated
    return 0;

    return 0;
}