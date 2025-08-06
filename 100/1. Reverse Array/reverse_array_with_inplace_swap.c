#include <stdio.h>

void inplace_swap(int *a, int *b)
{
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}

void reverse_array(int ar[], int len)
{
    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        inplace_swap(&ar[left], &ar[right]);
        left++;
        right--;
    }
}

int main()
{
    // code
    int ar[5] = {1, 2, 3, 4, 5};

    size_t len = sizeof(ar) / sizeof(int);

    reverse_array(ar, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}