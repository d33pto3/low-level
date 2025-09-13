#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// int main(int argc, char **argv)
int main(int argc, char *argv[])
{
    int fd;
    char ch;
    int num_bytes = atoi(argv[2]);

    if (argc == 3)
    {
        fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644);

        if (fd == -1)
        {
            perror("open");
            return 1;
        }

        ch = 'x';

        for (int i = 0; i < num_bytes; i++)
        {
            if (write(fd, &ch, 1) == -1)
            {
                perror("write");
                close(fd);
                return 1;
            }
        }
    }
    else
    {
        fd = open(argv[1], O_WRONLY | O_CREAT, 0644);

        if (fd == -1)
        {
            perror("open");
            return 1;
        }

        ch = argv[3][0];

        for (int i = 0; i < num_bytes; i++)
        {
            if (lseek(fd, 0, SEEK_END) == -1)
            {
                perror("lseek");
                close(fd);
                return 1;
            }
            if (write(fd, argv[3], 1) == -1)
            {
                perror("write");
                close(fd);
                return 1;
            }
        }
    }

    close(fd);
    return 0;
}
