// Find the index of the longest ascending sequence

#include <stdio.h>

#define SENTINEL -1
#define ARR {2, 3, 4, 1, 2, 3, 4, 5, SENTINEL}

int find_longest_order(int A[], int n);
int len(int A[]);

int main(int argc, char *argv[]) {
    int A[] = ARR;
    int n = len(A);
    printf("The index of the longest run of ordered values: A[%d]\n", find_longest_order(A, n));
    return 0;
}

int find_longest_order(int A[], int n) {
    // Perform a linear search through the array, keeping track of the highest ascending index.
    // 2 counters: index counter, length counter. 
    // On top of that, 2 types of each counter will be required.
    // O(n) time complexity, O(1) space

    // Checker for low-element arrays
    if (n <= 0) {
        return -1;
    }

    int longest_len = 1;
    int longest_index = 0;

    int curr_len = 1;

    // Loop runs for 2+ elements
    for (int i = 1; i < n; i++) {
        // Track ascending order
        if (A[i] >= A[i-1]) {
            curr_len++;
        } else {
            curr_len = 1;
        }
        
        // Track highest length 
        if (curr_len > longest_len) {
            longest_len = curr_len;
            longest_index = i+1 - curr_len;
        }

    }
    return longest_index;
}

int len(int A[]){
    // Return the length of the array EXCLUDING THE SENTINEL VALUE
    int i = 0;
    while (A[i] != SENTINEL) {
        i++;
    }
    return i;
}