#include <stdio.h>
#include <string.h>

int strlonger(char *s, char *t)
{
    return strlen(s) - strlen(t) > 0;
    // return ((int)strlen(s) - (int)strlen(t)) > 0; //correct
}

int main()
{
    // code

    char s1[] = "a";
    char s2[] = "aaaa";

    // int res = strlonger(s1, s2);

    printf("%lu\n", strlen(s1));
    printf("%lu\n", strlen(s2));

    printf("%u", strlen(s1) - strlen(s2));

    return 0;
}