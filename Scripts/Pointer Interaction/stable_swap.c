// This is a version of the swap function in quicksort. 
// Its purpose is to make quicksort a stable sorting algorithm. 
// Its runtime degenerates to N from constant.
// This function is untested so it is not clear if this is the correct implementation for all swap cases in quicksort.
typedef int flex_t;

void stable_swap(flex_t A[], int fe, int next);

void stable_swap(flex_t A[], int fe, int next) {
    // T: n, S: 1
    flex_t temp;
    while (next > fe) {
        temp = A[next];
        A[next] = A[next-1];
        A[next-1] = temp;
        next -= 1;
    }
    return;
}