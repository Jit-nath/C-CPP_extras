#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100

// Function to solve 0/1 Knapsack Problem using Dynamic Programming
int knapsack(int weight[], int value[], int n, int W)
{
    // dp[i][w] will store the maximum value for the first i items and capacity w
    int dp[n + 1][W + 1];

    // Build the dp table in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // If no item or capacity is 0, the value is 0
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            // If the current item can be included in the knapsack
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = (dp[i - 1][w] > value[i - 1] + dp[i - 1][w - weight[i - 1]]) ? dp[i - 1][w] : value[i - 1] + dp[i - 1][w - weight[i - 1]];
            }
            // Otherwise, exclude the current item
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value will be in dp[n][W]
    return dp[n][W];
}

int main()
{
    // Example data: weights and values of items
    int weight[] = {1, 3, 4, 5};
    int value[] = {1, 4, 5, 7};
    int n = 4; // Number of items
    int W = 7; // Knapsack capacity

    printf("Maximum value in Knapsack = %d\n", knapsack(weight, value, n, W));
    return 0;
}
