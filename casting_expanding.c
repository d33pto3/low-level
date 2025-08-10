#include <stdio.h>

// fun1 extracts a value from the low-order 8 bits of the argument, giving an integer ranging between 0 and 255.
int fun1(unsigned word)
{
    return (int)((word << 24) >> 24);
}

// fun1 extracts a value from the low-order 8 bits of the argument, but it also performs sign extension. This result will be an integer ranging between 0 and 255.
int fun2(unsigned word)
{
    return ((int)word << 24) >> 24;
}

int main()
{
    // code
    unsigned x = 118;

    int fx = fun1(x);

    printf("%x", fx);

    return 0;
}