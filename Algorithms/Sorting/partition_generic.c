// A generic implementation of the 3-way partition algorithm. Used by a generic quicksort algorithm.
// This funtion returns void but does manipulate pointer values.
// T: O(n)
// S: O(1)

typedef int flex_t;

void partition(flex_t A[], int n, flex_t *pivot, int *first_eq, int *first_gt);

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