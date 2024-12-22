#include <stdio.h>

/* Define the function */
#define f(x, y) ((y * y - x * x) / (y * y + x * x))

int main() {
    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
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

    /* Runge-Kutta Method */
    printf("\n   x0       y0       yn\n");
    printf("---------------------------\n");
    for (i = 0; i < n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        printf("%7.4f  %7.4f  %7.4f\n", x0, y0, yn);
        x0 += h;
        y0 = yn;
    }

    /* Display result */
    printf("\nValue of y at x = %.2f is %.3f\n", xn, yn);

    return 0;
}

