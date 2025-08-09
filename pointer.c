#include <stdio.h>
int main()
{
    // code
    int n = 10;
    int *p = &n;
    int **pp = &p;

    // print address of n
    printf("%p\n", &n);
    printf("%p\n", p);
    printf("%p\n\n", *pp);

    // print address of pointer p
    printf("%p\n", &p);
    printf("%p\n\n", pp);

    // print address of pointer pp
    printf("%p\n\n", &pp);

    // print value of n
    printf("%d\n", n);
    printf("%d\n", *p);   // dereferencing a pointer
    printf("%d\n", **pp); // dereferencing pointer of a pointer

    return 0;
}