#include <stdio.h>
#include <stdlib.h>

void mtr(int *ptr, size_t size)
{
    int *end = ptr + size;

    while (ptr != end)
    {
        int temp = *ptr;
        *ptr = *ptr + 1;
        printf("%d", *ptr);
        ptr++;
    }
}

int main()
{
    // code
    int *ptr = malloc(5 * sizeof(int));

    if (ptr == NULL)
    {
        printf("Allocation was not successful\n");
        exit(0);
    }

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &ptr[i]);
    }

    mtr(ptr, 5);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", ptr[i]);
    // }

    return 0;
}