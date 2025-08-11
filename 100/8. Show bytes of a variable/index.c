#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%.2X ", start[i]);
    printf("\n");
}

int main()
{
    // code
    int n = 10;

    show_bytes((byte_pointer)&n, sizeof(int));

    return 0;
}