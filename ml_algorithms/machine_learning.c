#include "machine_learning.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define LEARNING_RATE 0.01
#define NUM_ITERATIONS 1000

// Sigmoid function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Function to perform Linear Regression
void linearRegression(double* x, double* y, int n, double* slope, double* intercept) {
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_x_squared = 0.0;
    double sum_xy = 0.0;

    // Calculate the sums required for linear regression
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x_squared += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    // Calculate the slope (m) and intercept (b) of the best-fit line
    *slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    *intercept = (sum_y - (*slope) * sum_x) / n;
}

// Logistic regression training
void logisticRegression(double** X, double* y, int m, int n, double* weights) {
    for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
        double gradient[n];
        for (int j = 0; j < n; j++) {
            gradient[j] = 0.0;
            for (int i = 0; i < m; i++) {
                double prediction = sigmoid(weights[0] * X[i][0] + weights[1] * X[i][1] + weights[2] * X[i][2]);
                double error = y[i] - prediction;
                gradient[j] += error * X[i][j];
            }
            gradient[j] /= m;
            weights[j] += LEARNING_RATE * gradient[j];
        }
    }
}