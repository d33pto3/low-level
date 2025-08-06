#include <stdio.h>

void reverse_array(int ar[], int len)
{
    int right = len - 1;
    for (int left = 0; left < right; left++, right--)
    {
        int tmp = ar[left];
        ar[left] = ar[right];
        ar[right] = tmp;
    }
}

int main()
{
    // code
    int ar[5] = {1, 2, 3, 4, 5};

    size_t len = sizeof(ar) / sizeof(int);

    reverse_array(ar, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}