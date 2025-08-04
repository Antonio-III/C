#include <stdio.h>

typedef int flex_t;

void print_array(flex_t A[], int n);

void print_array(flex_t A[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}