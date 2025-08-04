#include <stdio.h>

typedef int flex_t;

void print_array(flex_t A[], int n);

void print_array(flex_t A[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	flex_t A[] = {1, 2, 3};
	int n = 3;

	print_array(A, n);
	return 0;
}