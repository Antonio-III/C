// This modified partition follows a more relaxed specification of the partition function described by the exercise in FOA Lecture 9 2024. Do remember that 1 call of the partition does not necessarily sort the array completely.
// This version of partition is also called the Lomuto-style partition.

typedef int data_t; 

int partition(data_t A[], int n);

int 
partition(data_t A[], int n) {
    // T: O(n)
    data_t pivot = A[n-1];
    int i = -1;
    
    for (int j = 0; j < n-1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[n-1]);
    return i;
}