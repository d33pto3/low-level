#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkReverse(const char *str1, const char *str2)
{
    if (strlen(str1) != strlen(str2))
    {
        return 0;
    }

    int len = strlen(str1);

    for (int i = 0; i <= len / 2; i++)
    {
        if (str1[i] != str2[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int checkPalindrome(const char *str)
{
    int len = strlen(str);

    for (int i = 0; i <= len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return 0;
    }

    return 1;
}

int main()
{
    char *str1 = malloc(10);
    // char *str2 = malloc(10);

    // scanf("%s", str2);
    while (1)
    {
        // %9s - because we allocated 10 bytes of heap memory for it
        // So, the string will be 9 bytes [1 byte for '\0']
        scanf("%9s", str1);

        if (!strcmp(str1, "exit"))
            break;

        if (checkPalindrome(str1))
        {
            printf("Yes, Palindrome!\n");
        }
        else
        {
            printf("Not Palindrome!\n");
        }
    }

    free(str1);
    // free(str2);

    return 0;
}