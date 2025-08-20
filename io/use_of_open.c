#include <stdio.h>
#include <stdlib.h>
// Declares file control options, constants, and function prototypes for low-level file operations for
// open(), fcntl(), and file access flags (e.g., O_RDONLY, O_CREAT)
#include <fcntl.h>
// Declares POSIX operating system API functions such as read(), write(), close(), lseek()
#include <unistd.h>
// Declares data structures and constants for file status information, such as stat sturcture and file perission macros
// e.g -> S_IRUSR, S_IWUSR
#include <sys/stat.h>

int main()
{
    int fd;

    // ------------------
    // Example: O_TRUNC
    // ------------------
    printf("Demo: O_TRUNC\n");

    // open existing file "my_file.txt" or create it, truncate contents
    fd = open("myfile.txt", O_RDWR | O_CREAT | O_TRUNC,
              S_IRUSR | S_IWUSR);

    // EXIT_FAILURE = 1
    // EXIT_SUCCESS = 0
    if (fd == -1)
    {
        perror("open myfile.txt");
        exit(EXIT_FAILURE);
    }

    // write new content
    write(fd, "Hello TRUNC in\n", 15);
    close(fd);

    // ---------------------
    // Example 2: O_APPEND
    // ---------------------
    printf("Demo O_APPEND\n");

    // Open Existing file "log.txt" or create it, always append
    fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND,
              S_IRUSR | S_IWUSR);

    if (fd == -1)
    {
        perror("open log.txt");
        exit(EXIT_FAILURE);
    }

    // Append multiple lines
    write(fd, "First log line\n", 15);
    write(fd, "Second log line\n", 16);

    printf("log.txt opened in append mode, new lines added.\n");

    return 0;
}