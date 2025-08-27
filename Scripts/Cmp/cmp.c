#include <stdio.h>


typedef int data_t;

int cmp(data_t *x1, data_t *x2);

int 
cmp(data_t *x1, data_t *x2) {
	return (*x1 - *x2);
}

int
main(int argc, char *argv[]) {
    int x1 = 2;
    int x2 = 3;
    printf("x1 - x2 = %d\n", cmp(&x1, &x2));
    return 0;
}