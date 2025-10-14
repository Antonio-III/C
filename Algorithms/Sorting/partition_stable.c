// This module is a modification of the partition function in quicksort. The modification allows quicksort to preserve the order of items with equal keys. That is to say, the first instance of duplicate keys is preserved to be the first instance of duplicate keys as opposed to the original quicksort which shuffles the equal keys.
// T: O(n)
// S: O(n)
// Courtesy of ChatGPT.

typedef flex_t;

void stable_partition(flex_t A[], int n, flex_t *pivot, int *fe, int *fg);

void stable_partition(flex_t A[], int n, flex_t *pivot, int *fe, int *fg) {
    flex_t *L = malloc(n *sizeof(flex_t));
    flex_t *E = malloc(n *sizeof(flex_t));
    flex_t *R = malloc(n *sizeof(flex_t));
    int l=0, e=0, r=0;

    for (int i=0; i<n; i++) {
        int outcome = cmp(&A[i], pivot);
        if (outcome < 0) L[l++] = A[i];
        else if (outcome > 0) R[r++] = A[i];
        else E[e++] = A[i];
    }

    memcpy(A, L, l * sizeof(flex_t));
    memcpy(A+l, E, e * sizeof(flex_t));
    memcpy(A+l+e, R, r * sizeof(flex_t));

    *fe = l;
    *fg = l+e;

    free(L); free(E); free(R);
}