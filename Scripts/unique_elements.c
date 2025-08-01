// Find the amount of unique elements in an array

#include <stdio.h>

#define ARR {1, 2, 3}
#define SIZE 3

int unique_elems_of_A(int A[], int n);
int is_unique(int n, int unique[], int size);

int main(int argc, char *argv[]) {
	int A[] = ARR;
	printf("The amount of unique numbers in the array is: %d\n", unique_elems_of_A(A, SIZE));
	return 0;
}

int unique_elems_of_A(int A[], int size){
	int unique[size];

    int unique_size = 0;
	
	for (int i = 0; i < size; i++) {
		if (is_unique(A[i], unique, unique_size)) {
			unique[unique_size] = A[i];
            unique_size += 1;
		}
	}
	return unique_size;
}

int is_unique(int A_i, int unique[], int size){
	// Find if the current number A_i appears in the uniques-only list
	for (int i = 0; i < size; i++) {
		if (A_i == unique[i]) {
			return 0;
		}
	}
	return 1;
}