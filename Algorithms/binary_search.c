#include <stdio.h>

typedef int data_t;

#define FOUND 1
#define NOT_FOUND -1

#define SENTINEL -1
#define ARR {1, 2, 3, 5, SENTINEL}

#define X 5


// n is len(A), x is target.
int binary_search_itr(data_t A[], int n, data_t *key, int *locn);
int binary_search_rec(data_t A[], int lo, int hi, data_t *key, int *locn);

int len(int array[]);
int cmp(data_t *x1, data_t *x2);

int 
main(int argc, char *argv[]) {
	data_t A[] = ARR;
	data_t key = X;

	int n = len(A);

	int locn, out;

	// handle output based on results.
	// Recursive is called like binary_search_rec(A, 0, n, &i, &locn)
	if ((out = binary_search_itr(A, n, &key, &locn)) == NOT_FOUND) {
		printf("x is not in A.\n");
	} else {
		printf("x is A[%d] of A\n", locn);
	}
	
	return 0;
}

int 
binary_search_itr(data_t A[], int n, data_t *key, int *locn) {
	int low = 0, high = n;
	int mid, outcome;
	
    // Rewrite to adjust to the new parameters
	while (low < high) {
        // Integer division guarantees an integer quotient
		mid = (low + high) / 2;
		if ((outcome = cmp(key, A+mid)) < 0) {
			high = mid;
		} else if (outcome > 0) {
			low = mid + 1;
		} else {
			*locn = mid;
			return FOUND;
		}
	}
	return NOT_FOUND;
}

int 
binary_search_rec(data_t A[], int low, int high, data_t *key, int *locn) {
	int mid, outcome;
	if (low >= high) {
		return NOT_FOUND;
	}

	mid = (low + high) / 2;

	if ((outcome = cmp(key, A+mid)) < 0) {
		return binary_search_rec(A, low, mid, key, locn);
	} else if (outcome > 0) {
		return binary_search_rec(A, mid+1, high, key, locn);
	} else {
		*locn = mid;
		return FOUND;
	}
}

int 
len(int A[]) {
    int i = 0; 
    while (A[i] != SENTINEL) {
        i++;
    }
    return i;
}

int 
cmp(data_t *x1, data_t *x2) {
	return (*x1 - *x2);
}