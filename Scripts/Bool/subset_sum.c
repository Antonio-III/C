// This script answers: "Is there a subset of A that sum to T?"

#include <stdio.h>
#include <stdlib.h>

int subsetsum(int A[], int n, int k);

int main(int argc, char *argv[]) {
    int A[] = {
    34, 38, 39, 43, 55, 66, 67, 84, 85, 91,
    101, 117, 128, 138, 165, 168, 169, 182, 184, 186,
    234, 238, 241, 276, 279, 288, 386, 387, 388, 389,
    413, 444, 487, 513, 534, 535, 616, 722, 786, 787
    };
    // default states
    int n = 20, k = 1000;

    if (argc == 3) {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }

    printf("n=%d, k=%d, subsetsum=%d\n", 
    n, k, subsetsum(A, n, k));
    
    return 0;
}

int subsetsum(int A[], int n, int k) {
    if (k == 0) return 1;
    else if (n == 0) return 0;
    
    else return subsetsum(A, n-1, k-A[n-1]) || subsetsum(A, n-1, k);
}

int __subset_sum_rec(int A[], int n, int k) {
    if (k == 0) return 1;
    else if (n == 0) return 0;
    
    else return subsetsum(A, n-1, k-A[n-1]) || subsetsum(A, n-1, k);
}

int __subset_sum_itr(int A[], int n, int k) {

    int dp[n+1][k+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int j = 0; j <= k; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (A[i-1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j - A[i-1]];
        }
    }
    return dp[n][k];
}

// Flattened ver.
int __subset_sum_itr_v2(int A[], int n, int k) {
    int dp[k+1];
    dp[0] = 1;
    for (int j = 1; j <= k; j++) dp[j] = 0;

    for (int i = 0; i <= n; i++)
        for (int j = k; j >= A[i]; j--) dp[j] = dp[j] || dp[j - A[i]];
    
    return dp[k];
}