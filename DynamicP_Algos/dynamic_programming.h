#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

// Function to compute the nth Fibonacci number using memoization
int fibonacciMemoization(int n);

// Function to compute the nth Fibonacci number using tabulation
int fibonacciTabulation(int n);

// Function to compute the length of the Longest Common Subsequence (LCS)
int longestCommonSubsequence(char* X, char* Y, int m, int n);

// Function to solve the Knapsack Problem
int knapsack(int* weights, int* values, int n, int W);

// Function to solve the Matrix Chain Multiplication problem
int matrixChainMultiplication(int* dims, int n);

// Function to compute the Edit Distance between two strings
int editDistance(char* s1, char* s2);

#endif
