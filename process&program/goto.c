#include <stdio.h>
int main()
{
    FILE *fp = fopen("noexistent.txt", "r");

    if (fp == NULL)
    {
        goto error;
    }

    printf("File opened successfully");
    fclose(fp);
    return 0;

error:
    printf("Error: could not open file\n");
    return 1;

    return 0;
}