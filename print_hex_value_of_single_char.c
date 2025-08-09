#include <stdio.h>
int main()
{
    // code
    int n = 100;
    char c = (char)n;

    char *cp = &c;

    for (int i = 0; i < sizeof(char); i++)
    {
        printf("%.2x ", cp[i]);
    }

    return 0;
}