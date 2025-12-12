#include <stdio.h>

typedef int data_t;

#define FOUND 1
#define NOT_FOUND -1

#define SENTINEL -1
#define ARR {1, 2, 3, 5, SENTINEL}

#define X 5

int binary_search_itr(data_t A[], int n, data_t *key, int *locn);
int binary_search_rec(data_t A[], int lo, int hi, data_t *key, int *locn);

int len(int array[]);
int cmp(data_t *x1, data_t *x2);

int 
main(int argc, char *argv[]) {
    data_t A[] = ARR;
    data_t key = X;

    int n = len(A);

    int locn, out;

    // handle output based on results.
    // Recursive is called like binary_search_rec(A, 0, n, &i, &locn)
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
    
    // Rewrite to adjust to the new parameters
    while (low < high) {
        // Integer division guarantees an integer quotient
        mid = low + (high - low)/2;
        if ((outcome = cmp(key, A+mid)) < 0) {
            high = mid;
        } else if (outcome > 0) {
            low = mid + 1;
        } else {
            *locn = mid;
            return FOUND;
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

    // Safer mid point formula and is equivalent to (low + high)/2 because when you expand the safer formula, 
    // it becomes: low + high/2 - low/2. And when you add the lows together: low - low/2 = low/2.
    // Now, the formula is low/2 + high/2. And when you simplify it: (low + high)/2
    // The safer formula avoids overflow. Courtesy of ChatGPT.
    mid = low + (high - low)/2;

    if ((outcome = cmp(key, A+mid)) < 0) {
        return binary_search_rec(A, low, mid, key, locn);
    } else if (outcome > 0) {
        return binary_search_rec(A, mid+1, high, key, locn);
    } else {
        *locn = mid;
        return FOUND;
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