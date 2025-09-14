// AI Generated

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// Define iovec for portability
struct iovec
{
    void *iov_base; // buffer start
    size_t iov_len;
};

ssize_t my_readv(int fd, const struct iovec *iov, int iovcnt)
{
    ssize_t total_read = 0;

    for (int i = 0; i < iovcnt; i++)
    {
        size_t bytes_left = iov[i].iov_len;
        char *buffer = (char *)iov[i].iov_base;

        while (bytes_left > 0)
        {
            ssize_t n = read(fd, buffer, bytes_left);
            if (n == 0)
            {
                // EOF
                return total_read;
            }
            if (n == -1)
            {
                return (total_read > 0) ? total_read : -1;
            }

            buffer += n;
            bytes_left -= n;
            total_read += n;
        }
    }

    return total_read;
}