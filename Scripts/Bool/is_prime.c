// Determine whether or not a number is a prime number.

int isprime(int n);

int isprime(int n) {
    // Prime numbers are by definition greater than 1.
    if (n <= 1) {
        return 0;
    }


    // A number `n` is a prime if any preceeding number `divisor` (2 to sqrt(n) inclusive) squared is at most equal to `n` and can divide `n`.
    // For instance, `n = 9`.`divisor` iteratively takes a value in the range [2, 3], and divides `n`. If a valid divisor is found (i.e. no remainders), the loop terminates prematurely. In the example, `divisor` takes in the value of 2, but 2 cannot fully divide 9, so `divisor` takes in the next value. 3 is a valid divisor for 9, so the loop terminates and returns `false`. 
    // Had `divisor` taken in a value outside the range, `n` would be a prime.
    for (int divisor = 2; divisor*divisor <= n; divisor++) {
        if (!(n % divisor)) {
            return 0; 
        }
    }
    
    return 1;
}