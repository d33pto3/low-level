#include <stdio.h>
#include <stdlib.h>

int nmaxSubArraySum(int arr[], int size);
int kmaxSubarrarySum(int arr[], int size);

int main()
{
    int arr[7] = {2, 3, -8, 7, -1, 2, 3};

    int size = sizeof(arr) / sizeof(int);

    printf("Answer to Maximum Subarray Sum:\n");
    printf("Kadane's Algorithm: %d\n", kmaxSubarrarySum(arr, size));
    printf("Naive Approach: %d\n", nmaxSubArraySum(arr, size));

    return 0;
}