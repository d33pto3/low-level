#include <stdio.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return "";

    char *prefix = strs[0]; // take the first string as reference
    int prefixLen = strlen(prefix);

    for (int i = 1; i < strsSize; i++)
    {
        char *cur = strs[i];

        int j = 0;

        // Compare characters using pointers
        while (j < prefixLen && *(prefix + j) && *(cur + j) && *(prefix + j) == *(cur + j))
        {
            j++;
        }

        // shrink the prefix length
        prefixLen = j;

        if (prefixLen == 0)
            return "";

        *(prefix + prefixLen) = '\0';
        return prefix;
    }
}

int main()
{
    char str1[] = "flower";
    char str2[] = "flight";
    char str3[] = "flow";

    char *arr[] = {str1, str2, str3};
    int size = sizeof(arr) / sizeof(arr[0]);

    char *result = longestCommonPrefix(arr, size);
    printf("Longest common prefix: %s\n", result);

    return 0;
}