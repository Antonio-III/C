#include <stdio.h>

#define ARR {7,6,5,4,3,2,1}
#define N 7

void bubble_sort(int A[], int n);
void int_swap(int *p1, int *p2);
void print_arr(int A[], int n);

int main(void) {
    int A[] = ARR;
    
    printf("Before sorting:\n");
    print_arr(A, N);
    
    bubble_sort(A, N);
    
    printf("After sorting:\n");
    print_arr(A, N);
    
    return 0;
}


void bubble_sort(int A[], int n) {
    // array elements are indexed based on how many increments away
    // they are from the first element. The first element is indexed at 0.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int_swap(&A[j], &A[j + 1]);
            }
        }
    }
    return;
}


void int_swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

void print_arr(int A[], int n) {
    printf("A = {");

    for (int i = 0; i < n; i++) {
        if (i == n - 1){
            // no whitespace
            printf("%d", A[i]);
        } else {
            printf("%d, ", A[i]);
        }
    }

    printf("}\n");
    return;
}