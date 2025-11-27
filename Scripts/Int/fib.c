#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(long long n);

static long long __fib_rec(long long n);
static long long __fib_itr(long long n);
static unsigned long long __fib_itr_mem(long long n);


int main(int argc, char *argv[]) {
    long long n;
    printf("What is n?\n");
    if (scanf("%lld", &n) != 1) return 1;

    unsigned long long x = fib(n);
    printf("n=%lld, fib=%lld", n, x);
    return 0;
}

unsigned long long fib(long long n) {
    return __fib_itr(n);
}

static long long __fib_rec(long long n) {
    if (n <= 2) return 1;
    return __fib_rec(n-1) + __fib_rec(n-2);
}

static long long __fib_itr(long long n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;
    
    unsigned long long s=0, a1=1, a2=1;
    for (long long _=3; _<=n; _++) {
        s = a1 + a2;
        a1 = a2;
        a2 = s;
    }
    return s;
}

static unsigned long long __fib_itr_mem(long long n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;

    unsigned long long dp[n];
    dp[0] = 1;
    dp[1] = 1;

    for (long long i=2; i<n; i++) dp[i] = dp[i-2] + dp[i-1];
    return dp[n];
}