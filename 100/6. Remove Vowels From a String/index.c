#include <stdio.h>
#include <limits.h>

void remove_vowels(char *str)
{
    if (*str == '\0')
        return;

    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u')
    {
        int i = 0;
        while (str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }
        remove_vowels(str);
    }
    else
        remove_vowels(++str);
}

void printt(char *str)
{
    while (*str != '\0')
    {
        printf("%c", *str);
        ++str;
    }
}

int main()
{
    // code
    char str[] = "ovwel";

    remove_vowels(str);

    printt(str);

    return 0;
}