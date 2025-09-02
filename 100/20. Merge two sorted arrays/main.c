#include <stdio.h>
#include <stdlib.h>

int *merge_array(int *ar1, int *ar2, int len1, int len2)
{
    int len = len1 + len2;

    int *ans = malloc(len * sizeof(int));

    if (ans == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int i = 0, j = 0;

    for (int k = 0; k < len; k++)
    {
        if (i < len1 && j < len2)
        {
            if (ar1[i] < ar2[j])
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
    int n, m;
    printf("Enter first array length: ");
    scanf("%d", &n);
    printf("Enter second array length: ");
    scanf("%d", &m);

    int *ar1 = malloc(n * sizeof(int));
    int *ar2 = malloc(m * sizeof(int));

    printf("First array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar1[i]);
    }

    printf("Second array:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &ar2[i]);
    }

    printf("Sorted array:\n");
    int *ans = merge_array(ar1, ar2, n, m);

    for (int i = 0; i < (n + m); i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    free(ar1);
    free(ar2);
    free(ans);

    return 0;
}