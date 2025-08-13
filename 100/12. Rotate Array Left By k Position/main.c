#include <stdio.h>

// fn prototype/declaration
void rotate_one_by_one(int arr[], int n, int k);

// Rotate array using reversal algorithm
void rotate_array_reversal_algo(int arr[], int size, int k)
{
}

int main()
{
    // code
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};

    rotate_one_by_one(arr, 7, 7);

    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}