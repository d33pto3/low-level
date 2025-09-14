#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// AI Generated
int main()
{
    int fd1, fd2;
    off_t offset;

    // open a test file (truncate if exists)
    fd1 = open("test_offset.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd1 == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Duplicate fd1
    fd2 = dup(fd1);
    if (fd2 == -1)
    {
        perror("dup");
        exit(EXIT_FAILURE);
    }

    // --- Test 1: Shared file offset ---
    write(fd1, "ABC\n", 4); // Write 4 bytes via fd1

    offset = lseek(fd2, 0, SEEK_CUR); // Check offset using fd2
    printf("Offset seen via fd2: %ld\n", (long)offset);

    // --- Test 2: Shared file offset flags ---
    int flags = fcntl(fd1, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    printf("Initial flags on fd1: 0x%x\n", flags);

    // Set O_APPEND on fd2
    if (fcntl(fd2, F_SETFL, flags | O_APPEND) == -1)
    {
        perror("fcntl F_SETFL");
        exit(EXIT_FAILURE);
    }

    // Now check flags via fd1
    int new_flags = fcntl(fd1, F_GETFL);
    printf("Flags on fd1 after setting O_APPEND via fd2: 0x%x\n", new_flags);

    close(fd1);
    close(fd2);

    return 0;
}