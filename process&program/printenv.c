#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }

    printf("getenv() fn to get environment by name\n");
    char *shell = getenv("SHELL");
    if (shell)
        printf("SHELL = %s\n", shell);

    return 0;
}