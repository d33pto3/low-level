#include <stdio.h>
#include <stdlib.h>

// Solution 1: using two pointer pointer(literally)
void mzte_using_tpp(int *ptr, size_t size)
{
    // read_ptr → scans every element in the array from start to end.
    // write_ptr → tracks where the next non-zero element should be placed.
    int *write_ptr = ptr, *read_ptr = ptr;

    for (size_t i = 0; i < size; i++)
    {
        if (*read_ptr != 0)
        {
            // *write_ptr++ → move the pointer forward
            // (*write_ptr)++ → increase the value at that location
            *write_ptr++ = *read_ptr;
        }
        read_ptr = read_ptr + 1;
    }

    int *end = ptr + size;

    while (write_ptr != end)
    {
        *write_ptr = 0;
        write_ptr = write_ptr + 1;
    }
}

// Solution 2: using two pointers
void move_zeroes(int arr[], int size)
{
    int write_idx = 0;

    for (int read_idx = 0; read_idx < size; read_idx++)
    {
        if (arr[read_idx] != 0)
        {
            arr[write_idx++] = arr[read_idx];
        }
    }

    while (write_idx < size)
    {
        arr[write_idx++] = 0;
    }
}

int main()
{
    // code
    size_t size = 5;
    int *ptr = malloc(size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Allocation was not successful\n");
        exit(0);
    }

    for (size_t i = 0; i < 5; i++)
    {
        scanf("%d", &ptr[i]);
    }

    // mzte_using_tpp(ptr, size);
    move_zeroes(ptr, (int)size);

    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}