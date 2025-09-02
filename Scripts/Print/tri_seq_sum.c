// Prints the nth term of the triangular number sequence.
// The module includes iterative and recursive solutions.
#include <stdio.h>

int t_itr(int n);
int t_rec(int n);

int main(int argc, char *argv[]){
    int n;

    printf("What is n? \n");
    scanf("%d", &n);

    printf("recursive: n=%d  Sum=%d \n", n, t_rec(n));
    printf("iterative: n=%d  Sum=%d \n", n, t_itr(n));
}

int t_itr(int n){
    int tri = 0;
    for (int inc = 1; inc <= n; inc++){
        tri+= inc;
    }

    return tri;
}

int t_rec(int n){
    if (n <= 0){
        return 0;
    } else {
        return n + t_rec(n-1);
    }
}