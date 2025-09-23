#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;

void fn()
{
    if (setjmp(env) == 0)
    {
        printf("setjmp() is called, returning normally from function\n");
        return; // leaving the function
    }
    else
    {
        // This code is never safe to reach
        printf("We should NOT be here: jumped into a dead function!\n");
    }
}

int main()
{
    fn(); // sets up the env and return

    printf("Now attempting longjmp() into fn() after it has returned\n");

    longjmp(env, 1); // Invalid, test already returned

    printf("This line will likely never be executed.\n");

    return 0;
}