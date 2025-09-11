// A generic implementation of the quickselect algorithm. 
// Due to the function returning a flexible data type, it is not recommended to pass an empty array to the function since it returns 0 by default, potentially causing a type mismatch.
// T: O(n) average and worst.
// S: O(1)

typedef int flex_t;

flex_t choose_pivot(flex_t A[], int n);

// Imports
void partition(flex_t A[], int n, flex_t *pivot, int *first_eq, int *first_gt);
flex_t cmp(flex_t *x1, flex_t *x2);
void swap(flex_t *p1, flex_t *p2);

flex_t quickselect(flex_t A[], int n, int k) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return A[0];
    }

    flex_t pivot = choose_pivot(A, n);
    
    int fe, fg;
    partition(A, n, &pivot, &fe, &fg);

    if (k <= fe) {
        return quickselect(A, fe, k);
    } else if (k <= fg) {
        return pivot;
    } else {
        return quickselect(A+fg, n-fg, k-fg);
    }
}


void 
partition(flex_t A[], int n, flex_t *pivot, int *first_eq, int *first_gt) {
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

    *first_eq = fe;
    *first_gt = fg;
    return; 
}

flex_t 
cmp(flex_t *x1, flex_t *x2) {
    if (*x1 < *x2) return -1;
    else if (*x1 > *x2) return 1;
    else return 0;
}

void swap(flex_t *p1, flex_t *p2) {
    flex_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}