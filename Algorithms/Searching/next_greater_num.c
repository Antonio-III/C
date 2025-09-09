// Find the next greatest number after the old number. Return old number if none exists.

int next_greater_num(int A[], int n, int old_num);

int next_greater_num(int A[], int n, int old_num) {
    // T: O(n) worst/average. 
    // S: O(1)
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