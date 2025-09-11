// A rudimentary implementation of copying an array's value to another array.
// T: O(n)
// S: O(n)

typedef int flex_t;

flex_t copy_array(flex_t A[], int n);

flex_t copy_array(flex_t A[], int n) {
    flex_t B[n];
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return B;
}