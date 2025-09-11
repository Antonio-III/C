// Implementation of an algorithm that finds the kth-smallest item in an unsorted array at O(nk) time at worst.
// T: O(nk) average, O(n^2) worst
// S: O(1)

#include <stdio.h>

#define ARR {1, 2, 3}
#define N 3

typedef int flex_t;

flex_t kth_smallest(flex_t A[], int n, int k);

// Imports
flex_t min(flex_t A[], int n);
flex_t cmp(flex_t *x1, flex_t *x2);
flex_t next_greater_num(flex_t A[], int n, flex_t old_num);

int 
main(int argc, char *argv[]) {
    int A[] = ARR;
    int n = N;
    int k;

    printf("Enter k:\n");
    if (scanf("%d", &k) != 1) {
        return 1;
    }
    printf("The kth smallest item is %d.\n", kth_smallest(A, n, k));
    return 0;
}

flex_t 
kth_smallest(flex_t A[], int n, int k) {
    flex_t candidate = min(A, n);
    
    for (int i = 1; i < k; i++) {
        candidate = next_greater_num(A, n, candidate);
    }
    return candidate;
}


flex_t 
min(flex_t A[], int n) {
    if (n <= 0) {
        return -1;
    }
    
    flex_t out = A[n-1];

    for (int i = 0; i < n-1; i++) {
        if (A[i] < out) {
            out = A[i];
        }
    }
    
    return out;
}


flex_t 
cmp(flex_t *x1, flex_t *x2) {
    return (*x1 - *x2); 
}


flex_t 
next_greater_num(flex_t A[], int n, flex_t old_num) {
    if (n <= 0) {
        return old_num;
    }

    int prev_cmp, next_cmp;

    flex_t new_num = old_num;
    int i, j;

    for (i = 0; i < n; i++) {
        if ((prev_cmp = cmp(&A[i], &old_num)) > 0) {
            new_num = A[i];
            break;
        }
    }
    
    for (j = i+1; j < n; j++) {
        if ((next_cmp = cmp(&A[j], &old_num)) > 0 && next_cmp < prev_cmp) {
            new_num = A[j];
        }
    }
    return new_num;
}