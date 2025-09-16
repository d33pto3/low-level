#include <stdio.h>
#include <stdlib.h>

// 1. Global initialized variable (Data segment - initialized)
int global_init = 42;

// 2. Global uninitialized variable (BSS)
// set to 0 by default
int global_unit;

// 3. Function to show code segment
void hello()
{
    printf("Hello from code segment!\n");
}

int main()
{
    // 4. Local variable (Stack)
    int local_var = 10;

    // 5. Dynamically allocated variable (Heap)
    int *heap_var = (int *)malloc(sizeof(int));
    *heap_var = 99;

    // Print addresses of each
    printf("Stack (local var):            %p\n", (void *)&local_var);
    printf("Heap (heap_var):              %p\n", (void *)&heap_var);
    printf("BSS segment(global_uninit):   %p-%d\n", (void *)&global_unit, global_unit);
    printf("Data Segment(global_init):    %p\n", (void *)&global_init);
    printf("Code Segment(function hello): %p\n", (void *)hello);

    free(heap_var);

    return 0;
}

// High addresses (e.g., 0x7fffffffffff)
// +-------------------------+
// |        Stack            |  grows DOWN
// |                         |
// +-------------------------+
// |      (Unused gap)       |
// +-------------------------+
// |        Heap             |  grows UP
// |                         |
// +-------------------------+
// |    BSS Segment          |
// +-------------------------+
// |  Data Segment           |
// +-------------------------+
// |  Text Segment (.text)   |
// Low addresses (e.g., 0x400000)