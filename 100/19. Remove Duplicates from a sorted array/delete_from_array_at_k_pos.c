#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 5;
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    // [1, 2, 3, 4, 5]

    int k = 2; // delete at index 2, value 3

    for (int i = k; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;

    arr = realloc(arr, size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}