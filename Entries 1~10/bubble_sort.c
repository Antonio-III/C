#include <stdio.h>

#define SENTINEL -1
#define array {8, 7, 9, 5, 0, 2, 4, -1}

void bubble_sort(int *p, int n);
void int_swap(int *p1, int *p2);
void print_array(int A[], int n);
int len(int A[]);

int main(void){
	int A[] = array;
	int n = len(A);
	
	printf("Before sorting:\n");
	print_array(A, n);
	
	bubble_sort(A, n);
	
	printf("After sorting:\n");
	print_array(A, n);
	
	return 0;
}


void bubble_sort(int *p, int n){
	// Array elements are indexed based on how many increments away
	// they are from the first element. The first element is indexed at 0.
	for (int i = 0; i < n; i++){
		for (int j = 0; j < (n - i) - 1; j++){
            // Remember that arrays decay into pointers. When A is passed, we are passing the ADDRESS of the first element of A.
            // p's value is an address, but can be subscripted to (effectively *(p+i)) increment and dereference the pointer. 
			if (p[j] > p[j + 1]){
				int_swap(&p[j], &p[j + 1]);
				}
		}
	}
	return;
}


void int_swap(int *p1, int *p2){
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	return;
}

void print_array(int A[], int n){
	printf("A = {");
	for (int i = 0; i < n; i++){
		if (i == n - 1){
			printf("%d", A[i]);
		} else{
			printf("%d, ", A[i]);
		}
	}
	printf("}\n");
	return;
}

int len(int A[]){
    int count = 0;
    for (int i = 0; A[i] != SENTINEL; i++){
        count++;
    }
    return count;
}