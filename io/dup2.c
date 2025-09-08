#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// int dup2(int oldfd, int newfd);
int main()
{
    int fd = open("out.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // redirect stdout (1) into the file
    if (dup2(fd, 1) == -1)
    // If newfd(1) was already open, it is closed first
    // Then newfd(1) is made to refer to the same open file description as oldfd(fd).
    // Return value = newfd.
    {
        perror("dup2");
        exit(1);
    }

    printf("Hello!\n");

    return 0;
}