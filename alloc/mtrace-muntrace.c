#include <mcheck.h>
#include <stdlib.h>

int main(void)
{
    mtrace();

    char *a = malloc(10); // never freed → leak
    char *b = malloc(20);
    free(b); // properly freed

    muntrace();
    return 0;
}
