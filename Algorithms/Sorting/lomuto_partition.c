// This modified partition follows a more relaxed specification of the partition function described by the exercise in FOA Lecture 9 2024. 
// Do remember that 1 call of the partition does not necessarily sort the array completely.
// This version of partition is also called the Lomuto partitioning scheme.

typedef int data_t; 

void partition(data_t A[], int n, int *f);

// imports
data_t *choose_pivot(data_t A[], int n);
void swap(data_t *p1, data_t *p2);


void 
partition(data_t A[], int n, int *f) {
    // T: O(n)
    data_t *pivot_ptr = choose_pivot(A, n);
    swap(pivot_ptr, &A[n-1]);
    
    data_t pivot = A[n-1];
    int i = -1;

    for (int j = 0; j < n-1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[n-1]);
    *f = i+1;
    return;
}

data_t 
*choose_pivot(data_t A[], int n) {
    return &A[0];

    // return &A[rand()%n];
    // return &A[n/2];
}

void 
swap(data_t *p1, data_t *p2) {
    data_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}