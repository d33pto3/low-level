#include <stdio.h>

int anagram_cf(char *, char *);

int main()
{
    // code
    char *str1;
    char *str2;

    scanf("%s", str1);
    scanf("%s", str2);

    if (anagram_cf(str1, str2))
        printf("Anagram\n");
    else
        printf("Not Anagram\n");

    return 0;
}