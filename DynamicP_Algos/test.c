#include <stdio.h>
#include "dynamic_programming.h"

int main() {
    // Test Fibonacci using memoization
    int n = 10;
    int fibMemo = fibonacciMemoization(n);
    printf("Fibonacci (Memoization) of %d: %d\n", n, fibMemo);

    // Test Fibonacci using tabulation
    int fibTab = fibonacciTabulation(n);
    printf("Fibonacci (Tabulation) of %d: %d\n", n, fibTab);

    // Test Longest Common Subsequence
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int nLCS = strlen(Y);
    int lcsLength = longestCommonSubsequence(X, Y, m, nLCS);
    printf("Length of Longest Common Subsequence: %d\n", lcsLength);

    // Test Knapsack Problem
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int nKnap = sizeof(values) / sizeof(values[0]);
    int W = 50;
    int knapResult = knapsack(weights, values, nKnap, W);
    printf("Knapsack Problem: Maximum value: %d\n", knapResult);

    // Test Matrix Chain Multiplication
    int dims[] = {10, 30, 5, 60};
    int nMatrixChain = sizeof(dims) / sizeof(dims[0]);
    int matrixChainResult = matrixChainMultiplication(dims, nMatrixChain);
    printf("Matrix Chain Multiplication: Minimum number of multiplications: %d\n", matrixChainResult);

    // Test Edit Distance
    char s1[] = "kitten";
    char s2[] = "sitting";
    int editDist = editDistance(s1, s2);
    printf("Edit Distance between '%s' and '%s' is %d\n", s1, s2, editDist);

    return 0;
}
