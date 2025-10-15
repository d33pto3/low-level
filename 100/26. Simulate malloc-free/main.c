// AI GENERATED

#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 1024 // Simulate memory size (1 KB)

char memory[MEMORY_SIZE]; // Our fake heap
bool used[MEMORY_SIZE];   // Track which bytes are "allocated" | Global scope - All false

// Simulated malloc
void *my_malloc(size_t size)
{
    // Simpler linear search for free space
    for (int i = 0; i < MEMORY_SIZE - size; i++)
    {
        bool spaceFree = true;
        // check for "size" sized contiguous free memory
        for (int j = 0; j < size; j++)
        {
            if (used[i + j])
            {
                spaceFree = false;
                break;
            }
        }

        if (spaceFree)
        {
            for (int j = 0; j < size; j++)
                used[i + j] = true;
            return &memory[i]; // return pointer to start of allocated block
        }
    }
    return NULL;
}

// Simulated free
void my_free(void *ptr, size_t size)
{
    int start = (char *)ptr - memory; // find offset
    for (int i = 0; i < size; i++)
    {
        used[start + i] = false;
    }
}

// Show memory map
void show_memory()
{
    for (int i = 0; i < 32; i++)
    {
        printf("%c", used[i] ? '#' : '.');
    }
    printf("\n");
}

int main()
{
    printf("Initial memory:\n");
    show_memory();

    void *p1 = my_malloc(8);
    void *p2 = my_malloc(10);

    printf("\nAfter 2 allocations:\n");
    show_memory();

    my_free(p1, 10);

    printf("\nAfter freeing first block:\n");
    show_memory();

    void *p3 = my_malloc(15);

    printf("\nAfter allocating 5 more bytes:\n");
    show_memory();

    return 0;
}