#include <stdio.h>

// this is swapping without third variable
void inplace_swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main()
{
    int x = 10, y = 20;
    inplace_swap(&x, &y);
    printf("%d %d", x, y);

    return 0;
}