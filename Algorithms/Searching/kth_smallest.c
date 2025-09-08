#include <stdio.h>

#define ARR {3, 2, 1}
#define N 3
#define SENTINEL -1

int kth_smallest(int A[], int n, int smallest, int sentinel);
int min(int A[], int n);

int main(int argc, char *argv[]) {
    int A[] = ARR;
    int n = N;

    int nth;

    // printf("Which kth smallest item do you want to find?\n");
    
    
    // if (scanf("%d", &nth) != 1) {
    //     printf("Invalid input. Program exit.\n");
    // }

    // printf("The kth smallest item is %d.\n", kth_smallest(A, n, nth, SENTINEL));
    printf("The min value of A is %d\n", min(A, n));
    return 0;
}

// The logic here is faulty.
int kth_smallest(int A[], int n, int nth, int sentinel) {
    // Helper function requires a sentinel value.
    // Array A must not have values lesser than -1.
    int out = min(A, n);

    for (int i = 0; i < nth-1; i++) {
        out = min(A, n);
    }
    return out;
}


int min(int A[], int n) {
    // Min function that uses a sentinel value.
    // Array A cannot values lesser than -1.
    int out = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            out = A[i];
            continue;
        }

        if (A[i] < out) {
            out = A[i];
        }
    }
    return out;
}