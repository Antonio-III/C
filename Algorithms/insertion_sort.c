#include <stdio.h>

#define ARR {12, 34, 55, 43, 66, 61, 18, 16, 29, 33, 19}
#define N 11

typedef int flex_t;

void insertion_sort(flex_t A[], int n);
void print_array(flex_t A[], int n);
void swap(flex_t *p1, flex_t *p2);

void 
insertion_sort(flex_t A[], int n) {
    // T: O((n-1)n/2)
    // S: O(1)
    int i, j;
	for (i = 1; i < n; i++) {
		for (j = i - 1; j >= 0 && A[j + 1] < A[j]; j--) {
			swap(&A[j], &A[j+1]);
		}
	}
}

void print_array(flex_t A[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}

void 
swap(flex_t *p1, flex_t *p2) {
    flex_t temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

int
main(int argc, char *argv[]) {
	int A[] = ARR;
	int n = N;
    printf("Before:");
    print_array(A, n);

	insertion_sort(A, n);

	printf("After:");
	print_array(A, n);
	
	return 0;
}