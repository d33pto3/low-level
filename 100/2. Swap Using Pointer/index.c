#include <stdio.h>

// using a temporary variable
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// inplcae swap - w/o using a third
void inplace_swap(int *a, int *b)
{
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}

int main()
{
    int a = 10, b = 20;
    // swap(&a, &b);
    inplace_swap(&a, &b);

    printf("%d %d", a, b);

    return 0;
}