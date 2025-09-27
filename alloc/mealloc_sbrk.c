#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Macro setting up an upper bound on how many allocations the program will attempt
// Used to size the ptr array and to validate user input
#define MAX_ALLOCS 1000000

// Simple helper for parsing integers from argv
static int getInt(const char *arg, const char *name)
{
    char *endptr;
    long val = strtol(arg, &endptr, 0);
    if (*endptr != '\0' || val <= 0)
    {
        fprintf(stderr, "Invalid value for %s: %s\n", name, arg);
        exit(EXIT_FAILURE);
    }
    return (int)val;
}

int main(int argc, char *argv[])
{
    // Array of pointers that will hold the addresses returned by malloc()
    // Each element will point to an allocated block. This array is stored on stack
    char *ptr[MAX_ALLOCS];

    //
    int freeStep, freeMin, freeMax, blockSize, numAllocs, j;

    if (argc < 3 || strcmp(argv[1], "--help") == 0)
    {
        fprintf(stderr,
                "Usage: %s num-allocs block size [step [min [max]]]\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse the first arg (number of allocations) as a positive integer
    numAllocs = getInt(argv[1], "num-allocs");

    // Check user didn't request more allocations then we can store in ptr array
    if (numAllocs > MAX_ALLOCS)
    {
        fprintf(stderr, "num-allocs > %d\n", MAX_ALLOCS);
        exit(EXIT_FAILURE);
    }

    // Parse the second argument: the size (in bytes) to allocate for each malloc().
    blockSize = getInt(argv[2], "block size");

    // Optional third argument: free every stepth
    freeStep = (argc > 3) ? getInt(argv[3], "step") : 1;
    // Optional fourth argument: staring index (1-based) of blocks to free; default 1
    freeMin = (argc > 4) ? getInt(argv[4], "min") : 1;
    // Optional fifth argument: ending index (1-based) of blocks to free; default numAllocs
    freeMax = (argc > 5) ? getInt(argv[5], "max") : numAllocs;

    // Validate freeMax doesn't exceed the allocated count
    if (freeMax > numAllocs)
    {
        fprintf(stderr, "free-max > numAllocs\n");
        exit(EXIT_FAILURE);
    }

    printf("Initial program break %10p\n", sbrk(0));

    printf("Allocating %d blocks * %d bytes each\n", numAllocs, blockSize);

    // Loop numAllocs times to allocate memory blocks.
    for (j = 0; j < numAllocs; j++)
    {
        // Allocate blockSize bytes and store the returned pointer in ptr[j]. malloc() returns NULL on failure.
        ptr[j] = malloc(blockSize);
        if (ptr[j] == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    // Print program break after allocations — usually higher than the initial break (heap grew).
    printf("Program break is now: %10p\n", sbrk(0));

    // which subset of blocks will be freed.
    printf("Freeing blocks from %d to %d in steps of %d\n",
           freeMin, freeMax, freeStep);

    for (j = freeMin - 1; j < freeMax; j += freeStep)
    {
        free(ptr[j]);
    }

    printf("After free(), program break is: %10p\n", sbrk(0));

    return EXIT_SUCCESS;
}

// run: ./mealloc_sbrk 1000 1024
// output:

// Initial program break 0x5a0e3eac6000

// Allocating 1000 blocks * 1024 bytes each

// explanation:
// - We are about to allocate 1000 memory blocks, each 1kb
// - Internally malloc may
// - - Use the existing free heap space (if available)
// - - Extend the heap via brk() / sbrk() if there's not enough space
// - - possibly use mmap() for large allocations (but 1kb * 1000 = ~1MB), ususally small enough for heap expansion.

// Program break is now: 0x5a0e3ebce000

// explanation:
// - 0x5a0e3ebce000 - 0x5a0e3eac6000 = 0x166000
// - 0x166000 = 1,495,296 bytes ≈ 1.43 MB
// - You allocated 1000 blocks × 1024 bytes = 1,024,000 bytes ≈ 1 MB.
// - Extra ~0.43 MB comes from:
// - - malloc bookkeeping (metadata for each block)
// - - alignment padding (heap blocks are aligned to multiples of 16 or 8 bytes)
// - So it makes sense — heap grew beyond the exact requested memory.

// Freeing blocks from 1 to 1000 in steps of 1

// After free(), program break is: 0x5a0e3eae9000

// explanation
// - 0x5a0e3ebce000 - 0x5a0e3eae9000 = 0x200f000
// - Before free: 0x5a0e3ebce000
// - After free:  0x5a0e3eae9000
// - Difference: 0x16F000  (1,557,376 bytes ≈ 1.49 MB)

// Observation:

// - The program break did not return fully to its original location (0x5a0e3eac6000)

// - Only partially shrank (~1.49 MB instead of 1.43 MB original allocation).

// - This happens because malloc may release only the top-most contiguous heap blocks back to the OS. The rest remains in the allocator’s free list for future allocations.

// - Key Takeaways

// Heap grew during allocation → program break increased.

// - Freeing memory doesn’t necessarily shrink the heap fully → program break may stay almost the same.

// - Program break is slightly reduced only if the freed blocks are at the top of the heap and contiguous.

// - The allocator keeps freed memory for reuse rather than returning it all to the OS immediately.