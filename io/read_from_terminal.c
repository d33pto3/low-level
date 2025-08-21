#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_READ 20

void errExit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main()
{
    char buffer[MAX_READ + 1]; // +1 for 0

    ssize_t n = read(STDIN_FILENO, buffer, MAX_READ);

    if (n == -1)
        errExit("read"); // Terminates the program with a failure status

    buffer[n] = '\n';

    printf("The input data was %s\n", buffer);

    return 0;
}