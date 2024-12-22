#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float x[20], y[20][20], xp, h, first_derivative;
    int i, j, n, index = -1;

    /* Input number of data points */
    printf("Enter number of data points: ");
    scanf("%d", &n);

    /* Input data for x and y */
    printf("Enter data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    /* Input the value of x for derivative calculation */
    printf("Enter the value of x for derivative calculation: ");
    scanf("%f", &xp);

    /* Check if xp exists in the dataset */
    for (i = 0; i < n; i++) {
        if (fabs(xp - x[i]) < 1e-6) { // Small tolerance for floating-point comparison
            index = i;
            break;
        }
    }

    /* If xp is not found, exit the program */
    if (index == -1) {
        printf("Invalid calculation point. Program exiting...\n");
        return 1;
    }

    /* Generate the Backward Difference Table */
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }

    /* Display the Backward Difference Table (Optional) */
    printf("\nBackward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%0.2f", x[i]);
        for (j = 0; j <= i; j++) {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    /* Calculate the first derivative using Backward Difference Formula */
    h = x[1] - x[0]; // Assuming uniform spacing
    first_derivative = y[index][1] / h;

    /* Displaying final result */
    printf("\nFirst derivative at x = %0.2f is %0.2f\n", xp, first_derivative);

    return 0;
}

