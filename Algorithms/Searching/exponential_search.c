// Generic implementation of the exponential search algorithm.
#include <stdio.h>

#define ARR {1, 2, 3}
#define N 3

int exponential_search(int A[], int n, int x);

int main(int argc, char *argv[]) {
    int A[] = ARR;
    int n = N;
    int x, i;

    printf("Enter x:\n");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input. Program exit.\n");
        return 0;
    }
    i = exponential_search(A, n, x);
    if (i >= n) {
        printf("%d is greater than all the elements.\n");
    } else {
        printf("%d could be found at A[%d], if it exists.\n", x, i);
    }
    return 0;
}


int exponential_search(int A[], int n, int x) {
    if (n == 0) return 0;
    if (A[0] >= x) return 0;
    if (A[n-1] < x) return n;

    int bound = 1;
    while (bound < n && A[bound] < x) {
        bound *= 2;
    }

    int left = bound / 2;
    int right = (bound < n) ? bound : n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}