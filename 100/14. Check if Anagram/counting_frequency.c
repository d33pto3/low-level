// check anagram using Counting Frequency
int anagram_cf(char *str1, char *str2)
{
    // Count arrays
    int c1[256] = {0};
    int c2[256] = {0};

    int i = 0;

    // count freq of str1
    while (str1[i])
        c1[str1[i++]]++;

    i = 0;

    // count freq of str2
    while (str2[i])
        c2[str2[i++]]++;

    // If any character count mismatch
    // strings are not anagrams
    for (i = 0; i < 256; i++)
    {
        if (c1[i] != c2[i])
            return 0;
    }

    // String are anagram is all frequencies match
    return 1;
}