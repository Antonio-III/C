// Return the next prime number after n.

// TODO: Find a way to include the dependent fn
#include <../Bool/is_prime.c>

int next_prime(int n);

int next_prime(int n) {
    // T: O(n(2^n))
    // S: O(1)
    int next_p = n + 1;

    while(!isprime(next_p)) {
        next_p++;
    }
    
    return next_p;
}