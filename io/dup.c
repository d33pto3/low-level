#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    // Both fd1 and fd2 point to the same OFD (open fd)
    int fd1 = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd2 = dup(fd1);

    // After write(fd1, "Hello ", 6), the file offset advances by 6
    write(fd1, "Hello ", 6);
    // When fd2 writes, it starts at offset 6
    write(fd2, "World", 5);

    return 0;
}