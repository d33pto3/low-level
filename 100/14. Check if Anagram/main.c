#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "flow";
    char str2[] = "wolv";

    int anagram = 1;

    if (strlen(str1) != strlen(str2))
    {
        printf("Not Anagram!");
        return 0;
    }
    else
    {
        int len = strlen(str1);

        int pos[len];

        for (int i = 0; i < len; i++)
        {
            pos[i] = 0;
        }

        for (int i = 0; i < len; i++)
        {
            char cur = str1[i];

            for (int j = 0; j < len; j++)
            {
                if (!pos[j] && cur == str2[j])
                {
                    // printf("%d - %c\n", j, str2[j]);
                    pos[j] = 1;
                    break;
                }

                if (j == len - 1)
                {
                    anagram = 0;
                }
            }

            if (!anagram)
                break;
        }
    }

    if (!anagram)
    {
        printf("Not Anagram!");
    }
    else
    {
        printf("Anagram!");
    }

    return 0;
}