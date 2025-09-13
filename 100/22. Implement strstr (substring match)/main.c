#include <stdio.h>
#include <string.h>

char *strs(const char *s1, const char *s2)
{
    if (!*s2)
        return (char *)s1;

    for (int i = 0; s1[i]; i++)
    {
        int j = 0;
        while (s1[i + j] && s2[j] && s1[i + j] == s2[j])
        {
            j++;
        }

        if (!s2[j])
        {
            return (char *)&s1[i];
        }
    }
    return NULL;
}

int main()
{
    char s1[] = "toebirama";
    char s2[] = "raman";
    char *p;

    p = strs(s1, s2);

    if (p)
    {
        printf("String found\n");
        printf("First occurrence of string '%s' in '%s' is "
               "'%s'\n",
               s2, s1, p);
    }
    else
    {
        printf("String not found\n");
    }

    return 0;
}