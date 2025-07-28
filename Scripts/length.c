// Calcualte the length of an array using 0 as a sentinel value.
#include <stdio.h>

#define SENTINEL 0

// Paste array in the place of { ... }
#define ARR {2, 3, 4, 5, 11, 25, -1, 0}

int len(int array[]);

int main(int argc, char *argv[]) {
    int A[] = ARR;
	int length_of_arr = len(A);

    printf("The length of the array is %d\n", length_of_arr);
    return 0;

}

int len(int A[]) {
    int i = 0; 
    while (A[i] != SENTINEL) {
        i++;
    }
    return i;
}