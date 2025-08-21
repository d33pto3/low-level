#include <stdio.h>
#include <string.h>

int string_compare(char *s1, char *s2)
{
    while (*s1 != '\0' || *s2 != '\0')
    {
        printf("%c %p ", *s1, s1);
        printf("%c %p\n", *s2, s2);

        s1++;
        s2++;
    }
    return 0;
}

int main()
{
    char *str1 = "Hello";
    char *str2 = "Hel";

    printf("\n\n%d\n", string_compare(str1, str2));

    // printf("%d\n", strcmp(str1, str2));
    return 0;
}