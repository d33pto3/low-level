#include <stdio.h>
#include <stdlib.h>
int main()
{
    // code
    int r, c;

    printf("Enter row number: ");
    scanf("%d", &r);

    printf("Enter column number: ");
    scanf("%d", &c);

    // Allocate memory for row pointers
    int **arr = (int **)malloc(r * sizeof(int *));

    if (arr == NULL)
    {
        printf("Memory allocation failed!");
        exit(0);
    }

    // Allocate memory for each row
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(r * sizeof(int *));

        if (arr == NULL)
        {
            printf("Memory allocation failed!\n");

            // Free previously allocated rows before exitings
            for (int j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);

            exit(0);
        }
    }

    printf("Enter values for 2D array of length %d X %d:\n", r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }

    printf("2D Array:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    // Free each row
    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }

    // Free the row pointer arary
    free(arr);

    return 0;
}