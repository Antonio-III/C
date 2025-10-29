// Relative and Absoulute implementations of the compare function.
#include <stdio.h>

typedef int flex_t;

flex_t cmp(void *x1, void *x2);

// Relative comparison
// T: O(1). S: O(1)
int 
cmp(void *a, void *b) {
    flex_t *x = a;
    flex_t *y = b;

    if (*x < *y) return -1;
    else if (*x > *y) return 1;
    else return 0;
}

// Absolute comparison
// T: O(1). S: O(1)
flex_t 
cmp(void *a, void *b) { 
    flex_t *x = a;
    flex_t *y = b;

    return (*x - *y); 
}

int
main(int argc, char *argv[]) {
    int x1 = 2;
    int x2 = 3;
    printf("x1 - x2 = %d\n", cmp(&x1, &x2));
    return 0;
}