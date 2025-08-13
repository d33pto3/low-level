#include <stdio.h>
#include <stdlib.h>

void cfoe(int *ptr, int *freq, int size)
{
    for (int i = 0; i < size; i++)
    {
        freq[ptr[i]]++;
    }
}

int main()
{
    // Suppose value range: 1 - 1000
    int *freq = (int *)calloc(1000, sizeof(int));

    int *arr = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    cfoe(arr, freq, 10);

    for (int i = 0; i < 1000; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d: %d\n", i, freq[i]);
        }
    }

    return 0;
}