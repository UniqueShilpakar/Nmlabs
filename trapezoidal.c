#include <stdio.h>
#include <math.h>

/* Define function */
#define f(x) (1 / (1 + pow(x, 2)))

int main() {
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Validate input */
    if (subInterval <= 0) {
        printf("Error: Number of sub intervals must be greater than zero.\n");
        return 1;
    }

    /* Calculation */
    /* Finding step size */
    stepSize = (upper - lower) / subInterval;

    /* Finding Integration Value using Trapezoidal Rule */
    integration = f(lower) + f(upper); // First and last terms
    for (i = 1; i < subInterval; i++) {
        k = lower + i * stepSize;
        integration += 2 * f(k); // Summing terms with weight 2
    }
    integration *= stepSize / 2; // Final integration value

    /* Displaying result */
    printf("\nRequired value of integration is: %.3f\n", integration);

    return 0;
}



