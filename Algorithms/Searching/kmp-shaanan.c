#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define NOT_FOUND -1

int kmp(char target[], char pattern[]);
void buildFailureFunc(char pattern[], int m, int failure[]);
void printFailureFunc(char pattern[], int failure[]);


int main(int argc, char *argv[]) {
    char pattern[MAX_LEN], target[MAX_LEN];
    int pos;

    printf("Enter target string: ");
    fgets(target, MAX_LEN, stdin);
    target[strlen(target) - 1] = '\0';

    printf("Enter pattern string: ");
    fgets(pattern, MAX_LEN, stdin);
    pattern[strlen(pattern) - 1] = '\0';

    pos = kmp(target, pattern);

    if (pos == NOT_FOUND)
    {
        printf("Pattern string not found.\n");
    }
    else
    {
        printf("Pattern string found at T[%d]: %s\n", pos, target+pos);
    }

    return 0;
}

int kmp(char target[], char pattern[])
{
    int failure[MAX_LEN];
    int n = strlen(target);  // Length of target string
    int m = strlen(pattern); // Length of pattern string
    int s = 0;               // Iterator of target string
    int i = 0;               // Iterator of pattern string

    printf("Building failure function...\n");
    buildFailureFunc(pattern, m, failure);
    printFailureFunc(pattern, failure);
    printf("Searching...\n");
    // This is inclusive because if our pattern is m letters long, we can't
    // look for it at a location in the target string where the pattern 
    // length exceeds it.
    // See more at (1.)
    while (s <= n - m)
    {
        if (target[s + i] == pattern[i])
        {        // Character matches at pattern[i]
            i++; // Go to next character
            if (i == m) // We find the starting location.
                return s;
        }
        else 
        {                          // Character does not match 
            s += (i - failure[i]); // Restart and skip up to next possible 
                                   // match location
            // i is how many characters we've compared already, failure[i]
            // is where the next possible match is. Therefore i - failure[i]
            // is the max amount we can skip.
            // if failure[i] = -1, we just move to the next character in the
            // target string.
            // See more at (2.)
            i = failure[i];
            if (i < 0) 
            {
                i = 0; // Reset i if failure[i] = -1 so our pattern string
                // iterator is 0 and not an invalid index.
            }
        }
    }
    printf("Done searching!\n");
    return NOT_FOUND;
}

void buildFailureFunc(char pattern[], int m, int failure[])
{
    int s = 2; // Iterator of pattern string
    int c = 0; // Iterator of the matched prefix

    failure[0] = -1;
    failure[1] = 0; 

    while (s < m)
    { // m is the pattern string length
        if (pattern[c] == pattern[s - 1])
        {
            c++;
            failure[s] = c;
            s++;
        }
        else if (c > 0)
        {
            c = failure[c]; // Go back to the last place a prefix could
            // start from (and then sequentially check characters again)
        }
        else
        {
            failure[s] = 0;
            s++;
        }
    }
}

void printFailureFunc(char pattern[], int failure[])
{
    int m = strlen(pattern);

    printf("Failure function for pattern: \"%s\":\n", pattern);
    printf("Index:\t\t");
    for (int i = 0; i < m; i++)
    {
        printf("%3d", i);
    }
    printf("\nPattern:\t");
    for (int i = 0; i < m; i++)
    {
        printf("%3c", pattern[i]);
    }
    printf("\nFailure:\t");
    for (int i = 0; i < m; i++)
    {
        printf("%3d", failure[i]);
    }
    printf("\n");
}
