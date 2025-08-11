#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)calloc(5, sizeof(int));

    // this returns the sizeof(*pointer) - 8 for 64 bits system, 4 for 32 bits system
    size_t sz = sizeof(ptr);
    printf("%lu\n", sz);

    // C does not provide a built-in way to get the size of a dynamically allocated array from a pointer.

    for (int i = 0; i < 5; i++)
    {
        printf("%p: %d\n", &ptr[i], *ptr);
    }
}
