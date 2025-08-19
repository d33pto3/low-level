#include <stdio.h>
#include <unistd.h>

int main()
{
    // Before any redirection, stdout prints to the terminal (console)
    printf("This goes to terminal\n");

    // Redirection with freopen
    // This closes the old stdout stream and opens it pointing to out.txt
    // So, anything sent to stdout will go to out.txt
    freopen("out.txt", "w", stdout); // w - write mode
    // FILE *fropen (const char *filename, const char * mode, FILE *stream)

    printf("This goes to file\n");

    dprintf(1, "Direct write to fd 1\n"); // Might still go to terminal, not file
    // dprintf(int fd, const char *format, ...) - used to write formatted output to a specified file descriptor
}