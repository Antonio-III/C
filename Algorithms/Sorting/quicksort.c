#include <stdio.h>
#include <assert.h>

#define MAXVALS 11

typedef int data_t;

void quick_sort(data_t A[], int n);
data_t choose_pivot(data_t A[], int n);
void partition(data_t A[], int n, data_t pivot, int *first_eq, int *first_gt);

// imports
void print_array(data_t A[], int n);
data_t cmp(data_t *x1, data_t *x2);
void swap(data_t *p1, data_t *p2);

int
main(int argc, char *argv[]) {
    data_t numbers[MAXVALS] = 
        {33, 12, 55, 33, 66, 61, 18, 16, 29, 33, 19};
    int nnumbs = MAXVALS;
    
    printf("Before:");
    print_array(numbers, nnumbs);

    quick_sort(numbers, nnumbs);

    printf("After:");
    print_array(numbers, nnumbs);
    return 0;
}

void
quick_sort(data_t A[], int n) {
    int first_eq, first_gt;
    if (n <= 1) {
        return;	
    }
    // 1.
    data_t pivot = choose_pivot(A, n);

    // 2.
    partition(A, n, pivot, &first_eq, &first_gt);

    // 3.
    quick_sort(A, first_eq);
    quick_sort(A+first_gt, n-first_gt);
}

data_t 
choose_pivot(data_t A[], int n) {
    // 4.
    return A[0];

    // return &A[rand()%n];
    // return &A[n/2];
}

void 
partition(data_t A[], int n, data_t pivot, int *first_eq, int *first_gt) {

    // T: O(n) worst, O(log n) average
    int next = 0, fe = 0, fg = n, outcome;

    while (next < fg) {
        if ((outcome = cmp(A+next, &pivot)) < 0) {
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

    assert(0 <= fe);
    *first_eq = fe;
    *first_gt = fg;
    return; 
}

void 
print_array(data_t A[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
}


data_t 
cmp(data_t *x1, data_t *x2) {
    return (*x1 - *x2);
}

void swap(data_t *p1, data_t *p2) {
    data_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}