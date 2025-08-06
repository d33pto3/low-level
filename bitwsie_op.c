#include <stdio.h>

void bitwise_not(int n)
{
    int out = ~n;
    printf("%d", out);
}

int main()
{
    int a = 60, b = 5;
    bitwise_not(a + b);
}