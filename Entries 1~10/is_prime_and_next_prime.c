// Ask the user to enter a number `n`, and output if the inputted number is prime or not. 
// Then, output the next prime number after `n`.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isprime(int n);
int nextprime(int old_prime);

int main(int argc, char *argv[]){
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n)!=1){
        printf("No number entered!\n");
    }
    if (isprime(n)){
        printf("%d is a prime.\n", n);
    } else{
        printf("%d is not a prime.\n", n);
    }
    printf("%d is the next prime.\n",nextprime(n));
    return 0;
}

bool isprime(int n){
    // the video had this bit of code that I thought was unnecessary
    //if (n<2){
    //	return 0;
    //}
    for (int divisor=2; divisor*divisor<=n; divisor++){
        if (n%divisor==0){
            return false; 
            }
    }
    return true;
}

int nextprime(int old_prime){
    int next_prime=old_prime+1;
    while(isprime(next_prime)==false){
        next_prime++;
    }
    
    return next_prime;
}