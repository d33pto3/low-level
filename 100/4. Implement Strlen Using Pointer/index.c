#include <stdio.h>

int my_strlen(char *cp)
{
    int len = 0;
    while (*cp != '\0')
    {
        cp++;
        len++;
    }
    return len;
}

int main()
{
    // code
    char str[] = "abc";

    // print address of the string

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%x\n", &str[i]);
    // }

    int len = my_strlen(str);

    printf("%d\n", len);

    return 0;
}