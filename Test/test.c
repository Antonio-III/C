#include <stdio.h>

int test_f();

int main(int argc, char *argv[]) {
    printf("test_t = %d\n", test_f());
    return 0;
}

int test_f() {
    return -1 || -1;
}