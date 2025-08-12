#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    printf("%d", ptr[0]);
}