// This function is used in quicksort. Another version returns a pointer.
// This version is used for the generic implementation of quicksort.

typedef int flex_t;

flex_t choose_pivot(flex_t A[], int n);
flex_t 
choose_pivot(flex_t A[], int n) {
    // 4.
    return A[0];

    // return A[rand()%n];
    // return A[n/2];
}