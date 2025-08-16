#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count = 3;   // number of strings
    int length = 20; // max length of each string

    // Allocate array of char* (string pointers)
    char **arr = malloc(count * sizeof(char *));

    // Allocate space for each string
    for (int i = 0; i < count; i++)
    {
        arr[i] = malloc(length * sizeof(char *));
    }

    return 0;
}