#include <stdio.h>

/* Define the function */
#define f(x, y) ((x) + (y))

int main() {
    float x0, y0, xn, h, yn, slope;
    int i, n;

    /* Input initial conditions and parameters */
    printf("Enter Initial Condition:\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn: ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);

    /* Validate input */
    if (n <= 0 || xn < x0) {
        printf("Invalid input: Ensure number of steps is positive and xn > x0.\n");
        return 1;
    }

    /* Calculate step size (h) */
    h = (xn - x0) / n;

    /* Euler's Method */
    printf("\nx0\ty0\tslope\tyn\n");
    for (i = 0; i < n; i++) {
        slope = f(x0, y0);
        yn = y0 + h * slope;
        printf("%.4f\t%.4f\t%.4f\t%.4f\n", x0, y0,slope, yn);
        y0 = yn;
        x0 = x0 + h;
    }

    /* Display result */
    printf("\nValue of y at x = %.2f is %.3f\n", xn, yn);

    return 0;
}

