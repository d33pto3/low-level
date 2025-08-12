#include <stdio.h>
#include <stdlib.h>

// check failure of allocation of array
void check_alloc_failure(void *ptr, char *allocation_type)
{
    if (ptr == NULL)
    {
        printf("Memory %s Failed.\n", allocation_type);
        exit(0);
    }
}

int main()
{
    // Initially allocate memory for 5 integers
    int *ptr = (int *)malloc(5 * sizeof(int));

    // Check if allocation was succesfull
    check_alloc_failure(ptr, "Allocation");

    // Now we need to store 8 elements
    // Reallocate to store 8 inetegers
    // We should use a pointer
    // so we don't override ptr unless the realloc() is succesful
    // or else we lose the original pointer (ptr),
    // and with it, our original allocated data (memory leak)
    int *temp = (int *)realloc(ptr, 8 * sizeof(int));

    // Check if reallocation was unsuccessful
    check_alloc_failure(temp, "Reallocation");
    ptr = temp;

    // Assume we use only 5 elements now
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = (i + 1) * 10;
    }

    // Shrink the array back to 5 elements
    temp = (int *)realloc(ptr, 5 * sizeof(int));

    // check if shrinking was successful
    check_alloc_failure(temp, "Reallocation");
    ptr = temp;

    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);

    // Finally, free the memory when done
    free(ptr);

    return 0;
}