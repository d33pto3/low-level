#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("You have entered ");
    printf("%d arguments\n", argc);

    // Using a while loop to
    // iterate through arguments
    int i = 0;
    while (i < argc)
    {
        printf("Argument %d", i + 1);
        printf(": %s\n", argv[i]);

        i++;
    }

    return 0;
}