#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>

int main(void)
{
    // Open file for writing (create if not exists, truncate if exists)
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Prepare multiple buffers
    char *buf1 = "Hello ";
    char *buf2 = "world";
    char *buf3 = "!\n";

    struct iovec iov[3];
    iov[0].iov_base = buf1;
    iov[0].iov_len = strlen(buf1);

    iov[1].iov_base = buf2;
    iov[1].iov_len = strlen(buf2);

    iov[2].iov_base = buf3;
    iov[2].iov_len = strlen(buf3);

    // Write all buffers in one syscall
    ssize_t written = writev(fd, iov, 3);
    if (written == -1)
    {
        perror("writev");
        close(fd);
        return 1;
    }

    printf("writev(): wrote %zd bytes\n", written);

    close(fd);
    return 0;
}