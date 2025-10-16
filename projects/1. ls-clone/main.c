#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dirp;
    struct dirent *entry;

    dirp = opendir(".");

    if (dirp == NULL)
    {
        perror("Error opening directory");
        return 1;
    }

    while ((entry = readdir(dirp)) != NULL)
    {
        printf("%s ", entry->d_name);
    }

    printf("\n");

    closedir(dirp);

    return 0;
}