#include <stdio.h>
int main()
{
    // code
    char st_arr[5][10] = {"big", "bigger", "biggest"};

    char ans[10] = "";

    int wordCount = 3;

    for (int j = 0; j < 10; j++)
    {
        if (st_arr[0][j] == '\0')
            break;

        char currentChar = st_arr[0][j];
        int allMatch = 1;

        for (int i = 1; i < 3; i++)
        {
            if (st_arr[i][j] == '\0' || currentChar != st_arr[i][j])
            {
                allMatch = 0;
                break;
            }
        }

        if (!allMatch)
            break;

        ans[j] = currentChar;
    }

    printf("%s", ans);

    return 0;
}