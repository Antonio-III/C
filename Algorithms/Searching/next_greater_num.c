// Find the next greatest number after the old number. Return old number if none exists.
// Possible data types are integers and floats.
// T: O(n) average and worst
// S: O(1)

typedef int flex_t;

int next_greater_num(flex_t A[], int n, flex_t old_num);

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