// Determine if an array is sorted ascendingly or not. 
// Uses linear search algorithm.

#include <stdio.h>

#define SORTED 1
#define ARRAY {8, 7, 9, 5, 0, 2, 4}
#define N 7 

int is_sorted(int A[], int n);
void print_array(int A[], int n);

int main(int argc, char *argv[]) {
	int A[] = ARRAY;
	
    print_array(A, N);
	if (is_sorted(A, N)) {
		printf("is sorted.\n");
	} else {
		printf("is not sorted.\n");
	}
	return 0;
}

int is_sorted(int A[], int n) {
	// equivalent to `for n in A` in Python.
	for (int i = 0; i < n-1; i++){
		if (A[i] > A[i+1]) {
			return !SORTED; 
		}
	}
	return SORTED;
}

void print_array(int A[], int n){
	for (int i = 0; i < n-1; i++){
		printf("%d ", A[i]);
	}
	return;
}