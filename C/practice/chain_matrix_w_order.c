#include <stdio.h>
#include <limits.h>

// Function prototype for printOrder
void printOrder(int s[], int i, int j);

// Function to find the minimum number of scalar multiplications and also the optimal order
void matrixChainOrder(int p[], int n)
{
    // dp[i][j] stores the minimum number of multiplications needed to multiply matrices Ai..Aj
    int dp[n][n];

    // s[i][j] stores the index where the optimal split occurs for matrices Ai..Aj
    int s[n][n];

    // Initialize the diagonal of dp table to 0 as the cost of multiplying a single matrix is 0
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // Fill the dp table for chains of length 2 to n
    for (int chainLength = 2; chainLength <= n - 1; chainLength++)
    {
        for (int i = 0; i < n - chainLength; i++)
        {
            int j = i + chainLength - 1;
            dp[i][j] = INT_MAX;

            // Try all possible places to split the chain
            for (int k = i; k < j; k++)
            {
                // Calculate the cost of splitting at k
                int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                // Update the dp table and store the split position
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                    s[i][j] = k; // Record the split point
                }
            }
        }
    }

    // The minimum number of multiplications is in dp[0][n-2]
    printf("Minimum number of multiplications: %d\n", dp[0][n - 2]);

    // Print the optimal order of multiplication
    printf("Optimal multiplication order: ");
    printOrder(s, 0, n - 2);
    printf("\n");
}

// Helper function to print the optimal order of multiplication
void printOrder(int s[], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i + 1); // Print the matrix name
    }
    else
    {
        printf("(");
        printOrder(s, i, s[i * (j + 1) + j]);     // Print the left side of the split
        printOrder(s, s[i * (j + 1) + j] + 1, j); // Print the right side of the split
        printf(")");
    }
}

int main()
{
    // Example: dimensions of matrices A1, A2, A3, A4
    int p[] = {1, 2, 3, 4, 3}; // Dimensions: A1(1x2), A2(2x3), A3(3x4), A4(4x3)
    int n = sizeof(p) / sizeof(p[0]);

    matrixChainOrder(p, n);

    return 0;
}
