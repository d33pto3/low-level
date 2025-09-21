#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void second()
{
    printf("Inside second function\n");
    longjmp(env, 42); // Jump back to saved state
}

void first()
{
    if (setjmp(env) == 0)
    {
        printf("setjmp returned 0, calling second()\n");
        second();
    }
    else
    {
        printf("Back from longjmp! setjmp returned nonzero\n");
    }
}

int main()
{
    first();
    return 0;
}