#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    // code
    int fd = open("myfile.txt", O_CREAT | O_WRONLY, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Reserve 10 MB on disk from offset 0
    int ret = posix_fallocate(fd, 0, 10 * 1024 * 1024);

    if (ret != 0)
    {
        // ret is an error code (not -1)
        fprintf(stderr, "posix_fallocate failed: %d \n", ret);
        close(fd);
        return 1;
    }

    printf("10MB allocated successfully.\n");

    close(fd);
    return 0;
}