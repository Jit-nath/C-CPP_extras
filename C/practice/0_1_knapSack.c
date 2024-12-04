#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int m, int w[], int p[], int n) {
    int V[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        V[i][0] = 0;
    for (int j = 0; j <= m; j++)
        V[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i] > j) {
                V[i][j] = V[i - 1][j];
            } else {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + p[i]);
            }
        }
    }

    return V[n][m];
}

int main() {
    int p[] = {60, 100, 120}; // p=profit,w=weight
    int w[] = {10, 20, 30};
    int m = 50;
    int n = sizeof(p) / sizeof(p[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(m, w, p, n));
    return 0;
}