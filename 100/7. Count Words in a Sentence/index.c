#include <stdio.h>

//
const char *escape_leading_zeores(const char *sentence)
{
    if (*sentence == '\0') // if string is empty or only spaces
        return sentence;

    if (*sentence != ' ')
        return sentence;

    return escape_leading_zeores(sentence + 1);
}

//
void count_words(const char *sentence, int *cnt)
{
    if (*sentence == '\0')
        return;

    if (*sentence == ' ')
        ++*cnt;

    count_words(sentence + 1, cnt);
}

// count words in a sentence
void cwias(const char *sentence, int *cnt)
{
    // base case
    const char *trimmed = escape_leading_zeores(sentence);
    count_words(trimmed, cnt);
}

int main()
{
    // code
    char str[] = "       ";

    int cnt = 0;

    cwias(str, &cnt);

    cnt == 0 ? printf("0\n") : printf("%d\n", ++cnt);

    return 0;
}