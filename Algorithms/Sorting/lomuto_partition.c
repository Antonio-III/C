// This modified partition follows a more relaxed specification of the partition function described by the exercise in FOA Lecture 9 2024. Do remember that 1 call of the partition does not necessarily sort the array completely.
// This version of partition is also called the Lomuto-style partition.

typedef int data_t; 

void partition(data_t A[], int n);

void 
partition(data_t A[], int n) {
    // T: O(n)

    int i = 0;
    data_t pivot = A[0];

    // Note how we start at a value above the pivot.
    for (int j=1; j<n; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[j], &pivot);
        }
    }
    swap(&A[0], &A[i]);
    return i;
}