// function declaration
long mult2(long, long);

void multstore(long x, long y, long *dest)
{
    long t = mult2(x, y);
    *dest = t;
}

// generate assembly code
// linux >  gcc -Og -S file_name.c

// generate assembly code and object-code file
// linux > gcc -Og -c file_name.c

// Show binary/object file in hexadecimal value
// linux > objdump d mstore.o