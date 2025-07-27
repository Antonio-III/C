// A program that calculates how many days has it been since Dec 31.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isprime(int n);
int nextprime(int old_prime);

int main(int argc, char *argv[]){
    int n;
    
    printf("Enter a number: ");
    
    if (scanf("%d", &n) !=1){
        printf("No number entered!\n");
    }

    if (isprime(n)){
        printf("%d is a prime.\n", n);
    } else{
        printf("%d is not a prime.\n", n);
    }

    printf("%d is the next prime.\n", nextprime(n));

    return 0;
}

bool isprime(int n){
    // Prime numbers are by definition greater than 1.
    if (n <= 1){
        return false;
    }


    // A number `n` is a prime if any preceeding number `divisor` (2 to sqrt(n) inclusive) squared is at most equal to `n` and can divide `n`.
    // For instance, `n = 9`.`divisor` iteratively takes a value in the range [2, 3], and divides `n`. If a valid divisor is found (i.e. no remainders), the loop terminates prematurely. In the example, `divisor` takes in the value of 2, but 2 cannot fully divide 9, so `divisor` takes in the next value. 3 is a valid divisor for 9, so the loop terminates and returns `false`. 
    // Had `divisor` taken in a value outside the range, `n` would be a prime.
    for (int divisor = 2; divisor*divisor <= n; divisor++){
        if (!(n%divisor)){
            return false; 
            }
    }
    
    return true;
}

int nextprime(int old_prime){
    int next_prime=old_prime+1;

    while(!isprime(next_prime)){
        next_prime++;
    }
    
    return next_prime;
}