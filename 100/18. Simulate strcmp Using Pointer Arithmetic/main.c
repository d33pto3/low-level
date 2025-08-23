#include <stdio.h>
#include <string.h>

int string_compare(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main()
{
    char *str1 = "He";
    char *str2 = "Hel";

    printf("%d\n", string_compare(str1, str2));

    printf("%d\n", strcmp(str1, str2));
    return 0;
}