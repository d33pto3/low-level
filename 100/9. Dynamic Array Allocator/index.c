#include <stdio.h>
#include <stdlib.h>

int main()
{
    // hold 5 integers
    // malloc return void * (generic pointer)
    // we cast this to int * (integer pointer)
    int *arr = (int *)malloc(5 * sizeof(int));

    // if there is no memory available, the malloc will fail and return NULL
    // so it is recommended to check for failure
    if (arr == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }

    for (int i = 0; i < 5; i++)
        arr[i] = i + 1;

    // print array address and value
    for (int i = 0; i < 5; i++)
        printf("%p: %d\n", &arr[i], arr[i]);

    return 0;
}