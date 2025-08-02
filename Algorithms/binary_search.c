#include <stdio.h>

#define NOT_FOUND -1
#define SENTINEL -1

#define ARR {1, 2, 3, SENTINEL}
#define X 5

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
	int lo = 0, hi = n, m;
    
	while (lo < hi) {
        // Integer division guarantees an integer quotient
		m = (lo + hi) / 2;
		if (x < A[m]) {
			hi = m;
		} else if (x > A[m]) {
			lo = m + 1;
		} else {
			return m;
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