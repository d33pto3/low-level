#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <filename> <text_to_append>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *text = argv[2];

    // Open file in write-only mode with O_APPEND and create if it doesn't exist
    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
    // 0644 (octal representation)
    // 6 - Read(4) and Write(2) for the owner == S_IRUSR | S_IWUSR
    // 4 - Read(4) for the group
    // 4 - Read(4) for others
    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    // Write text to the file
    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1)
    {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    bytes_written += (fd, "\n", 1);
    printf("Successfully appended %zd bytes to %s\n", bytes_written, filename);

    // Close the file
    close(fd);

    return EXIT_SUCCESS;
}