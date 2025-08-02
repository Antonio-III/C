#include <stdio.h>

#define NOT_FOUND -1
#define SENTINEL -1

#define ARR {1, 2, 3, SENTINEL}
#define X 3

// n is len(A), x is target.
int binary_search(int A[], int n, int x);
int len(int array[]);

int main(int argc, char *argv[]) {
	int A[] = ARR;
	int n = len(A);
	int i = binary_search(A, n, X);
	// handle output based on results.
	if (i >= 0) {
		printf("x is in A[%d] of A\n", i);
	} else {
		printf("x is not in A.\n");
	}
	
	return 0;
}

int binary_search(int A[], int n, int x) {
	int low = 0, high = n, mid;
    
	while (low < high) {
        // Integer division guarantees an integer quotient
		mid = (low + high) / 2;
		if (x < A[mid]) {
			low = mid;
		} else if (x > A[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return NOT_FOUND;
}

int len(int A[]) {
    int i = 0; 
    while (A[i] != SENTINEL) {
        i++;
    }
    return i;
}