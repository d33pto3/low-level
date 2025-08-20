#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int fd = open("myfile.txt", O_CREAT | O_EXCL | O_WRONLY, 0644);

    if (fd == -1)
    {
        if (errno == EEXIST)
        {
            printf("File already exists!\n");
        }
        else
        {
            perror("open");
        }

        exit(EXIT_FAILURE);
    }

    write(fd, "Hello", 5);
    close(fd);

    printf("File created successfully!\n");
    return 0;
}