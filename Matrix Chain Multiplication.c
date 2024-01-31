// matrix chain multiplication
#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 10

// Function to find the minimum number of scalar multiplications needed to
// parenthesize the given matrices efficiently and calculate the minimum cost.
int matrixChainMultiplication(int dims[], int n)
{
    int dp[MAX_MATRICES][MAX_MATRICES];

    // Initialize the diagonal elements to 0 since a single matrix requires no multiplication.
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // Calculate the minimum cost of multiplying matrices.
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            // Calculate the minimum cost of multiplying the subchain from i to j.
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The minimum cost will be in the top-right corner of the table.
    return dp[1][n];
}

int main()
{
    // Number of matrices
    int n;
    printf("Enter the number of matrices (maximum 10): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_MATRICES)
    {
        printf("Invalid number of matrices. Please enter a number between 1 and %d.\n", MAX_MATRICES);
        return 1;
    }

    // Dimensions of matrices (input at compile-time)
    int dims[MAX_MATRICES + 1];
    printf("Enter the dimensions of %d matrices:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dims[i]);
    }

    int minCost = matrixChainMultiplication(dims, n);
    printf("Minimum cost of matrix chain multiplication: %d\n", minCost);

    return 0;
}
