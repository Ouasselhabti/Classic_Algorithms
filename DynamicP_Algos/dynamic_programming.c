#include "dynamic_programming.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

// return the minimum of three integers
int min(int a, int b, int c) {
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}

// return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute the nth Fibonacci number using memoization
int fibonacciMemoizationUtil(int n, int* memo) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacciMemoizationUtil(n - 1, memo) + fibonacciMemoizationUtil(n - 2, memo);
    return memo[n];
}

int fibonacciMemoization(int n) {
    if (n < 0) {
        return -1; // Handle invalid input
    }

    int* memo = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    int result = fibonacciMemoizationUtil(n, memo);
    free(memo);

    return result;
}

// Function to compute the nth Fibonacci number using tabulation
int fibonacciTabulation(int n) {
    if (n < 0) {
        return -1; // Handle invalid input
    }

    if (n <= 1) {
        return n;
    }

    int* fib = (int*)malloc((n + 1) * sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int result = fib[n];
    free(fib);

    return result;
}

// Function to compute the length of the Longest Common Subsequence (LCS)
int longestCommonSubsequence(char* X, char* Y, int m, int n) {
    // Create a 2D array to store the LCS lengths
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    // Initialize the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int lcsLength = dp[m][n];

    // Free the dynamically allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return lcsLength;
}

int knapsack(int* weights, int* values, int n, int W) {
    // Create a 2D array to store the results of subproblems
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((W + 1) * sizeof(int));
    }

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int result = dp[n][W];

    // Free the dynamically allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int matrixChainMultiplication(int* dims, int n) {
    int dp[n][n];

    // Initialize dp array
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill dp array using bottom-up approach
    for (int cl = 2; cl < n; cl++) {
        for (int i = 1; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int editDistance(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D array to store the results of subproblems
    int dp[m + 1][n + 1];

    // Initialize the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If the first string is empty, insert all characters from the second string
            if (i == 0) {
                dp[i][j] = j;
            }
            // If the second string is empty, delete all characters from the first string
            else if (j == 0) {
                dp[i][j] = i;
            }
            // If the last characters match, no operation needed
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // If the last characters don't match, consider three operations: insert, delete, replace
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}