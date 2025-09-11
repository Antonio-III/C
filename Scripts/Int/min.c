// Min function that uses the last element as the starting lowest value and traverses the remaining subarray to find the lowest value.
typedef int flex_t;

flex_t min(flex_t A[], int n) {
    // T: O(n) average and worst, S: O(1) 
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