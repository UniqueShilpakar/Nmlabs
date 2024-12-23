#include <stdio.h>
#define f(x, y) 2 * (y) / (x)

int main() {
    float x, xp, y, h, m1, m2;

    // Input initial values
    printf("Enter initial values of x & y:\n");
    scanf("%f %f", &x, &y);

    // Input the x value to evaluate the function
    printf("Enter x at which function to be evaluated:\n");
    scanf("%f", &xp);

    // Input the step size
    printf("Enter the step size h:\n");
    scanf("%f", &h);

    // Heun's Method
    printf("\nIteration Details:\n");
    printf("x\t\ty\n");
    printf("---------------------\n");
    for (; x < xp; x += h) {
        m1 = f(x, y);
        m2 = f(x + h, y + h * m1);
        y = y + h / 2 * (m1 + m2);
        printf("%.4f\t%.4f\n", x, y); // Print intermediate values
    }

    // Output the result
    printf("\nFunction value at x = %.4f is %.4f\n", xp, y);

    return 0;
}

