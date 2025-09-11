// An implementation of the quickselect algorithm that makes a copy of the size of the passed array, 3 times. Can be used if no modification is allowed on the passed array, but it may be better to just copy the array first and then pass the copy to the generic implementation than using this function.
// Currently, the function returns 0 if no elements are passed. Therefore, it is not recommended to let flex_t be anything but int.
// T: O(n) average and worst.
// S: O(n)

typedef int flex_t;

// Imports
flex_t choose_pivot(flex_t A[], int n);

flex_t 
quickselect_kth(flex_t A[], int n, int k) {
    if (n <= 0) {
        return 0;
    }
    
    if (n == 1) {
        return A[0];
    }

    int pivot = choose_pivot(A, n);

    int *L = malloc(n *sizeof(flex_t));
    int *E = malloc(n *sizeof(flex_t));
    int *R = malloc(n *sizeof(flex_t));
    int l = 0, e = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] < pivot) L[l++] = A[i];
        else if (A[i] > pivot) R[r++] = A[i];
        else E[e++] = A[i];
    }
    
    flex_t result;

    if (k <= l) {
        result = quickselect_kth(L, l, k);
    } else if (k <= l + e) {
        result = pivot;
    } else {
        result = quickselect_kth(R, r, k - l - e);
    }

    free(L); free(E); free(R);
    return result;
}

flex_t 
choose_pivot(flex_t A[], int n) {
    return A[0];
}