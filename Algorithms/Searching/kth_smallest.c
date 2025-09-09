#include <stdio.h>

#define ARR {3, 2, 1}
#define N 3
#define SENTINEL -1

int kth_smallest(int A[], int n, int smallest, int sentinel);
int min(int A[], int n);
int cmp(int *x1, int *x2);

int main(int argc, char *argv[]) {
    int A[] = ARR;
    int n = N;


    int old_num = 22;
    printf("The next greater than %d is %d.\n", old_num, next_greater_num(A, n, old_num));
    return 0;
}

// The logic here is faulty.
int kth_smallest(int A[], int n, int nth, int sentinel) {
    int out;
    int prev_smallest = min(A, n);
    
    for (int i = 0; i < nth; i++) {
        for (int j = 0; j < n; j++) {
            if (A[j] < prev_smallest && A[j]) {
                continue;
            }
        }
    }
}


int min(int A[], int n) {
    // Min function that uses a sentinel value.
    // Array A cannot values lesser than -1.
    if (n <= 0) {
        printf("Min number not found. Returning -1 instead.\n.");
        return -1;
    }

    int out = A[n-1];
    for (int i = 0; i < n-1; i++) {
        if (A[i] < out) {
            out = A[i];
        }
    }
    return out;
}


int 
cmp(int *x1, int *x2) { 
    printf("x1=%d, x2=%d\n", *x1, *x2);
    return (*x1 - *x2); 
}