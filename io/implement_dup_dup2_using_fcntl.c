#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int my_dup(int oldfd)
{
    // F_DUPFD - command for duplicating a file descriptor
    // Third argument(100) - minimum value for the new file descriptor
    // which will be pointing to the same open file descriptor
    return fcntl(oldfd, F_DUPFD, 100);
}

int my_dup2(int oldfd, int newfd)
{
    if (oldfd == newfd)
    {
        if (fcntl(oldfd, F_GETFL) == -1) // checks validity of the oldfd
        {
            errno = EBADF;
            return -1;
        }

        return newfd;
    }

    if (fcntl(oldfd, F_GETFL) == -1)
    {
        errno = EBADF;
        return -1;
    }

    // close newfd if it is open
    close(newfd);

    // Duplicate oldfd to newfd
    int fd = fcntl(oldfd, F_DUPFD, newfd);
    if (fd == -1)
    {
        return -1;
    }

    return fd;
}

int main()
{
    int fd1 = open("tf.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);

    if (fd1 == -1)
    {
        perror("open");
        return 1;
    }

    write(fd1, "Og\n", 3);

    int fd2 = my_dup(fd1);

    if (fd2 == -1)
    {
        perror("my_dup");
        return 1;
    }

    write(fd2, "Duplicated with my_dup\n", 23);

    // specific fd = 10
    // freed if 10 is already in use
    int fd3 = my_dup2(fd2, 10);

    if (fd3 == -1)
    {
        perror("my_dup2");
        return 1;
    }

    write(fd3, "Duplicated with my_dup2\n", 24);

    close(fd1);
    close(fd2);
    close(fd3);

    printf("Writes completed. Check 'tf.txt'\n");

    return 0;
}