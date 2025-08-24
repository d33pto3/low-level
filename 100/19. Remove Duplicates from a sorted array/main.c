#include <stdio.h>
#include <stdlib.h>

int remove_dups(int *arr, int size);

int main()
{
    // int arr[5] = {10, 10, 10, 10, 10};
    // int size = 5;

    // int j = 0;

    // for (int i = 1; i < size; i++)
    // {
    //     if (arr[i] != arr[j])
    //     {
    //         j++;
    //         arr[j] = arr[i];
    //     }
    // }

    // size = j + 1;

    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");

    int size;
    printf("Array size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    size = remove_dups(arr, size);

    int *tmp = realloc(arr, size * sizeof(int));

    if (tmp == NULL && size > 0)
    {
        free(arr);
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    arr = tmp;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    printf("\n");

    return 0;
}