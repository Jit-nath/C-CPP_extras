#include <limits.h>
#include <stdio.h>

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(int p[], int n) {
    // dp[i][j] stores the minimum number of multiplications needed to multiply matrices Ai..Aj
    int dp[n][n];

    // Initialize the diagonal of the table to 0 because the cost of multiplying a single matrix is 0
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the table for chains of length 2 to n
    for (int chainLength = 2; chainLength <= n - 1; chainLength++) {
        for (int i = 0; i < n - chainLength; i++) {
            int j = i + chainLength - 1;
            dp[i][j] = INT_MAX;

            // Try all possible places to split the chain
            for (int k = i; k < j; k++) {
                // Calculate the cost of splitting at k
                int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                // Update the minimum cost
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    // Return the minimum number of multiplications needed to multiply matrices 1 to n
    return dp[0][n - 2];
}

int main() {
    // Example: dimensions of matrices A1, A2, A3, A4
    int p[] = {1, 2, 3, 4, 3}; // Dimensions: A1(1x2), A2(2x3), A3(3x4), A4(4x3)
    int n = sizeof(p) / sizeof(p[0]);

    printf("Minimum number of multiplications is: %d\n", matrixChainOrder(p, n));
    return 0;
}
