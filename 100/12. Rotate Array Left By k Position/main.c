#include <stdio.h>
#include <stdlib.h>

// fn prototype/declaration
// 1. rotate one by one
void rotate_one_by_one(int arr[], int n, int k);

// 2. Using temporary array

// 3. Using reversal algorithm
void reverse(int *, int, int);

int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));

    int n, k;

    printf("Enter array length(must be within 10):\n");
    scanf("%d", &n);
    printf("Enter rotate position:\n");
    scanf("%d", &k);

    printf("Enter numbers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    free(arr);

    return 0;
}