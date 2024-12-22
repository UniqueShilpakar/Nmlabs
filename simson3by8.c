#include <stdio.h>
#include <math.h>

/* Define the function to integrate */
#define f(x) (1 / (1 + (x) * (x)))

int main() {
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;

    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);
    printf("Enter number of sub intervals (must be a multiple of 3): ");
    scanf("%d", &subInterval);

    /* Input Validation */
    if (subInterval <= 0 || subInterval % 3 != 0) {
        printf("Error: Number of sub intervals must be a positive multiple of 3.\n");
        return 1;
    }

    if (upper <= lower) {
        printf("Error: Upper limit must be greater than lower limit.\n");
        return 1;
    }

    /* Calculation */
    /* Step size */
    stepSize = (upper - lower) / subInterval;

    /* Simpson's 3/8 Rule Calculation */
    integration = f(lower) + f(upper);
    for (i = 1; i < subInterval; i++) {
        k = lower + i * stepSize;
        if (i % 3 == 0) {
            integration += 2 * f(k);
        } else {
            integration += 3 * f(k);
        }
    }
    integration *= (3 * stepSize) / 8;

    /* Output the result */
    printf("\nRequired value of integration is: %.3f\n", integration);

    return 0;
}

