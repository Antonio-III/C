// This module is a modification of the cmp function. This cmp function is only used for quicksort.
// Courtesy of ChatGPT.

// For this stable comparison function to work, you need:
    // 1. A working stable partition.
    // 2. An updated input array to work with structs.

typedef int flex_t;

typedef struct {
    int value;
    int index;
} struct_t;

#define ARRAY {1, 2, 3}

int stable_cmp(const struct_t *a, const struct_t *b);
void initialize_struct_arrray(flex_t A[], int n, struct_t B[]);

int 
main(int argc, char *argv[]) {
    flex_t A[] = ARRAY;
    // Value based off ARRAY element count.
    int n = 3; 
    
    struct_t B[n];
    initialize_struct_arrray(A, n, B);
    // This is how quicksort would be called.
    // quicksort(B, etc., etc.)
    
    return 0;
}

int 
stable_cmp(const struct_t *a, const struct_t *b) {
    if (a->value < b->value) return -1;
    if (a->value > b->value) return 1;

    if (a->index < b->index) return -1;
    if (a->index > b->index) return 1;

    return 0;

}

void initialize_struct_arrray(flex_t A[], int n, struct_t B[]) {
    for (int i=0; i<n; i++) {
        B[i].value = A[i];
        B[i].index = i;
    }
    return;
}
