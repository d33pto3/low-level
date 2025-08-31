#include <stdio.h>
#include <stdlib.h>

int *merge_array(int *ar1, int *ar2)
{
    int len1 = (sizeof(ar1) / sizeof(int));
    int len2 = (sizeof(ar2) / sizeof(int));

    int len = len1 + len2;

    int *ans = malloc(len * sizeof(int));

    int i = 0, j = 0;

    for (int k = 0; k < len; k++)
    {
        if (i < len1 && j < len2)
        {
            if (ar1[i] < ar2[j])
            {
                ans[k] = ar1[i];
                i++;
                continue;
            }
            else
            {
                ans[k] = ar1[j];
                j++;
                continue;
            }
        }
        else if (i < len1)
        {
            ans[k] = ar1[i];
            i++;
        }
        else
        {
            ans[k] = ar2[j];
            j++;
        }
    }

    return ans;
}

int main()
{
    // code
    int ar1[3], ar2[3];

    for (int i = 0; i < 3; i++)
    {
        ar1[i] = i * 2 + 1;
    }

    for (int i = 0; i < 3; i++)
    {
        ar2[i] = i * 2 + 2;
    }

    int *ans = merge_array(ar1, ar2);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}