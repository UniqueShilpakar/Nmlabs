#include <stdio.h>
#include <math.h>

// Function to calculate factorial
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * fact(n - 1));
}

int main() {
    float x, x0, y, fdy, sdy, tdy;

    printf("Enter initial values of x and y: \n");
    scanf("%f %f", &x0, &y);

    printf("Enter x at which the function is to be evaluated: \n");
    scanf("%f", &x);

    // Calculate derivatives
    fdy = 2 * x0 + x0 * x0; // First Derivative
    sdy = 2 + 2 * x0 * fdy + 2 * y; // Second Derivative
    tdy = 2 * fdy + 2 * x0 * sdy; // Third Derivative

    // Calculate the value of y using Taylor Series
    y = y + (x - x0) * fdy
        + (pow(x - x0, 2) * sdy) / fact(2)
        + (pow(x - x0, 3) * tdy) / fact(3);

    printf("Function value at x = %.4f is %.4f\n", x, y);

    return 0;
}
