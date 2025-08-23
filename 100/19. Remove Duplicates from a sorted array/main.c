#include <stdio.h>
int main()
{
    int arr[5] = {10, 10, 10, 10, 10};
    int size = 5;

    int j = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    size = j + 1;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}