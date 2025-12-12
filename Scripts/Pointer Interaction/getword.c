/* 
The function takes standard input and extracts 1 word. A word is defined by a sequence of only alphabetical characters.

This is a helper function that's part of a bigger program. 
*/

#include <stdio.h>
#include <ctype.h>

int 
getword(char W[], int limit) {
    int c, len = 0;

    while ((c = getchar()) != EOF && !isalpha(c)) {
    }

    if (c == EOF) {
        return EOF;
    }

    W[len++] = c;
    while (len < limit && (c = getchar()) != EOF && isalpha(c)) {
        W[len++] = c;
    }

    W[len] = '\0';
    return 0;
}