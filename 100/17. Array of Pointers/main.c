#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
    }

    int **prr = (int **)malloc(5 * sizeof(int *));

    for (int i = 0; i < 5; i++)
    {
        *(prr + i) = (arr + i);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%p - %d\n", *(prr + i), *(arr + i));
    }

    free(arr);
    free(prr);

    return 0;
}