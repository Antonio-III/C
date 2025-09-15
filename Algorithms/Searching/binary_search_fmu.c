// Implementation of Binary Search that returns the index of the first match. Iterative and Recurive implementations are unified.
#include <stdio.h>

typedef int data_t;

#define FOUND 1
#define NOT_FOUND -1

#define SENTINEL -1
#define ARR {1, 1, 1, 1, SENTINEL}

#define X 1

int binary_search_itr(data_t A[], int n, data_t *key, int *locn);
int binary_search_rec_wrap(data_t A[], int n, data_t *key, int *locn);
int binary_search_rec(data_t A[], int lo, int hi, data_t *key, int *locn);

int len(int array[]);
int cmp(data_t *x1, data_t *x2);

int 
main(int argc, char *argv[]) {
    data_t A[] = ARR;
    data_t key = X;

    int n = len(A);

    int locn, out;

    if ((out = binary_search_itr(A, n, &key, &locn)) == NOT_FOUND) {
        printf("x is not in A.\n");
    } else {
        printf("x is A[%d] of A\n", locn);
    }
    
    return 0;
}

int 
binary_search_itr(data_t A[], int n, data_t *key, int *locn) {
    int low = 0, high = n;
    int mid, outcome;
    
    while (low < high) {
        mid = low + (high - low)/2;
        if ((outcome = cmp(key, A+mid)) < 0) {
            high = mid;
        } else if (outcome > 0) {
            low = mid + 1;
        } else {
            if (mid == low || cmp(key, A+mid-1) != 0) {
                *locn = low;
                return FOUND;
            }
            high = mid;
        }
    }

    return NOT_FOUND;
}

int 
binary_search_rec(data_t A[], int low, int high, data_t *key, int *locn) {
    int mid, outcome;
    
    if (low >= high) {
        return NOT_FOUND;
    }

    mid = low + (high - low)/2;

    if ((outcome = cmp(key, A+mid)) < 0) {
        return binary_search_rec(A, low, mid, key, locn);
    } else if (outcome > 0) {
        return binary_search_rec(A, mid+1, high, key, locn);
    } else {
        if (mid == low || cmp(key, A+mid-1) != 0) {
            *locn = mid;
            return FOUND;
        }
        return binary_search_rec(A, low, mid, key, locn);
    }
}

int 
len(int A[]) {
    int i = 0; 
    while (A[i] != SENTINEL) {
        i++;
    }
    return i;
}

int 
cmp(data_t *x1, data_t *x2) {
    if (*x1 < *x2) return -1;
    if (*x1 > *x2) return 1; 
    return 0;
    
}

int 
binary_search_rec_wrapper(data_t A[], int n, data_t *key, int *locn) {
    binary_search_rec(A, 0, n, key, locn);
}