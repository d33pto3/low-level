#include <stdio.h>
#include <string.h>

char *strs(const char *s1, const char *s2)
{
    int j = 0;
    char *p = NULL;
    for (int i = 0; i < strlen(s1); i++)
    {
        if (p == NULL)
        {
            if (s1[i] == s2[j])
            {
                p = (char *)&s1[i];
                j++;
                continue;
            }
        }
        else
        {
            if (s1[i] != s2[j])
            {
                p = NULL;
                j = 0;
            }
        }

        if (s1[i] == s2[j])
        {
            j++;
        }
    }

    return p;
}

int main()
{
    char s1[] = "toebirama";
    char s2[] = "ram";
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