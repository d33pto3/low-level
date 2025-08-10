// copy a string (no strcpy)

void my_strcpy(char *dest, char *src)
{
    // using while loop
    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';

    // using for loop
    // int i;
    // for (i = 0; src[i] != '\0'; ++i)
    // {
    //     dest[i] = src[i];
    // }
    // dest[i] = '\0';
}

#include <stdio.h>
int main()
{
    char mystr[] = "abc";

    char cpstr[sizeof(mystr)]; // enough for mystr[] + '/0'

    my_strcpy(cpstr, mystr);

    printf("%s\n", cpstr);
}