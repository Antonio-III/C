// This function is used in quicksort. Another version returns an element of array A.
// This version is used for a Lomuto-style partition function when you use a function to choose a pivot rather than using the last element directly.

typedef int flex_t;

flex_t *choose_pivot_ptr(flex_t A[], int n);
flex_t 
*choose_pivot_ptr(flex_t A[], int n) {
    return &A[0];

    // return &A[rand()%n];
    // return &A[n/2];
}