#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;

static void f2(void)
{
    longjmp(env, 2);
}

static void f1(int argc)
{
    if (argc == 1)
        longjmp(env, 1);
    f2();
}

int main(int argc, char *argv[])
{
    // code
    switch (setjmp(env))
    {
    case 0: // This is the return after initial setjmp();
        printf("Calling f1 after initial jump\n");
        f1(argc); // Never returns...
        break;    // ...but this is goood form

    case 1:
        printf("We jumped back from f1()\n");
        break;

    case 2:
        printf("We jumped back from f2()\n");
        break;
    }

    return 0;
}