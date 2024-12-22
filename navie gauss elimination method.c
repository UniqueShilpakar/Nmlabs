#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10

// Function to input the augmented matrix
void inputMatrix(float a[SIZE][SIZE], int n) {
    printf("Enter the augmented matrix (each row should have %d elements):\n", n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
}

// Function to perform Gauss Elimination
void gaussElimination(float a[SIZE][SIZE], float x[SIZE], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (fabs(a[i][i]) < 1e-6) { // Avoid division by zero
            printf("Mathematical Error: Division by zero detected.\n");
            exit(EXIT_FAILURE);
        }
        for (int j = i + 1; j < n; j++) {
            float ratio = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

// Function to display the solution
void displaySolution(float x[SIZE], int n) {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.3f\n", i + 1, x[i]);
    }
}

// Main function
int main() {
    int n;
    float a[SIZE][SIZE], x[SIZE];

    // Input number of unknowns
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    if (n <= 0 || n > SIZE) {
        printf("Error: Number of unknowns must be between 1 and %d.\n", SIZE);
        return EXIT_FAILURE;
    }

    // Input augmented matrix
    inputMatrix(a, n);

    // Perform Gauss Elimination
    gaussElimination(a, x, n);

    // Display solution
    displaySolution(x, n);

    return 0;
}
