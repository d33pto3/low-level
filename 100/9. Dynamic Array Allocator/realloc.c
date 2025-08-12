#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(5 * sizeof(int));

    printf("%p\n", ptr);

    // Reallocation
    int *temp = (int *)realloc(ptr, 10 * sizeof(int));

    // Only update the pointer if reallocation is successful
    if (temp == NULL)
    {
        printf("Memory Reallocation Failed\n");
        exit(0);
    }
    else
    {
        ptr = temp;
        printf("%p\n", ptr);
    }
}