#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    if (x == y)
        return;

    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int ar[], int cnt)
{
    int first, last;

    for (first = 0, last = cnt - 1; first <= last; first++, last--)
    {
        inplace_swap(&ar[first], &ar[last]);
    }
}

int main()
{
    int ar[5] = {10, 20, 30, 40, 50};

    size_t sz = sizeof(ar) / sizeof(int);

    reverse_array(ar, 5);

    for (int i = 0; i < sz - 1; i++)
    {
        printf("%d, ", ar[i]);
    }

    printf("%d", ar[sz - 1]);

    return 0;
}