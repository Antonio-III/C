#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define MAXVALS 11
#define ARR {33, 12, 55, 33, 66, 61, 18, 16, 29, 33, 19}

typedef int data_t;

void quick_sort(data_t A[], int n);
data_t choose_pivot(data_t A[], int n);
void partition(data_t A[], int n, data_t *pivot, int *first_eq, int *first_gt);

// imports
void print_array(data_t A[], int n);
data_t cmp(data_t *x1, data_t *x2);
void swap(data_t *p1, data_t *p2);

int 
main(int argc, char *argv[]) {
    data_t numbers[MAXVALS] = ARR;
    int nnumbs = MAXVALS;
    
    srand(time(NULL));
    printf("Before:");
    print_array(numbers, nnumbs);

    quick_sort(numbers, nnumbs);

    printf("After:");
    print_array(numbers, nnumbs);
    return 0;
}

void
quick_sort(data_t A[], int n) {
    // T: O(n^2) worst, O(nlogn) average
    // To get logn, our recursion depth must be logn at most while our partition remains n.
    
    if (n <= 1) {
        return;	
    }

    int first_eq, first_gt;

    // 1.
    data_t pivot = choose_pivot(A, n);

    // 2.
    partition(A, n, &pivot, &first_eq, &first_gt);

    // 3.
    quick_sort(A, first_eq);
    quick_sort(A+first_gt, n-first_gt);
}

data_t 
choose_pivot(data_t A[], int n) {
    // 4.
    return A[0];

    // return A[rand()%n];
    // return A[n/2];
}

void 
partition(data_t A[], int n, data_t *pivot, int *first_eq, int *first_gt) {
    // T: O(n)

    int next = 0, fe = 0, fg = n, outcome;

    while (next < fg) {
        if ((outcome = cmp(A+next, pivot)) < 0) {
            swap(A+fe, A+next);
            fe += 1;
            next += 1;
        } else if (outcome > 0) {
            fg -= 1;
            swap(A+next, A+fg);
        } else {
            next += 1;
        }
    }

    assert(0 <= fe && fe < fg && fg <= n);
    *first_eq = fe;
    *first_gt = fg;
    return; 
}

data_t 
cmp(data_t *x1, data_t *x2) {
    if (*x1 < *x2) return -1;
    else if (*x1 > *x2) return 1;
    else return 0;
}

void 
print_array(data_t A[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}

void 
swap(data_t *p1, data_t *p2) {
    data_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}