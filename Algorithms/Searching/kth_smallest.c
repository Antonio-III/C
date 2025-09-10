#include <stdio.h>

#define ARR {1, 1, 2}
#define N 3

int kth_smallest(int A[], int n, int k);

// Imports
int min(int A[], int n);
int cmp(int *x1, int *x2);
int next_greater_num(int A[], int n, int old_num);


int main(int argc, char *argv[]) {
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

int kth_smallest(int A[], int n, int k) {
    // T: O(nk) average, O(n^2) worst. S: O(1)
    int smallest = min(A, n);
    
    for (int i = 0; i < k-1; i++) {
        smallest = next_greater_num(A, n, smallest);
    }
    return smallest;
}


int min(int A[], int n) {
    if (n <= 0) {
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
    return (*x1 - *x2); 
}


int next_greater_num(int A[], int n, int old_num) {
    if (n <= 0) {
        return old_num;
    }

    int prev_cmp, next_cmp;

    int new_num = old_num;
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