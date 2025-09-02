// Complete implementation of the compare function.
#include <stdio.h>

typedef int flex_t;

flex_t cmp(flex_t *x1, flex_t *x2);

flex_t 
cmp(flex_t *x1, flex_t *x2) {
    return (*x1 - *x2);
}

int
main(int argc, char *argv[]) {
    int x1 = 2;
    int x2 = 3;
    printf("x1 - x2 = %d\n", cmp(&x1, &x2));
    return 0;
}