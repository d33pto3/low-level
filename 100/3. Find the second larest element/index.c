#include <stdio.h>
#include <limits.h>

// using two variables max and smax
int find_second_largest(int ar[], int len)
{
    int max = ar[0];
    int smax = INT_MIN;
    for (int i = 1; i < len; i++)
    {
        if (max < ar[i])
        {
            smax = max;
            max = ar[i];
        }
        else if (smax < ar[i] && max != ar[i])
        {
            smax = ar[i];
        }
    }

    return smax;
}

int main()
{
    // code
    int ar[5] = {10, 5, 10, 1};

    size_t len = sizeof(ar) / sizeof(int);

    int res = find_second_largest(ar, len);

    printf("%d", res);

    return 0;
}