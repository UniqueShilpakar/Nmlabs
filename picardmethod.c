#include <stdio.h>
#include <math.h>

// Define Picard's successive approximations
#define y1(x) (2 + (x) - 2.0 / 3.0 * pow((x), 3))
#define y2(x) (2 + (x) + pow((x), 2) - 2.0 / 3.0 * pow((x), 3) + pow((x), 4) / 4.0)
#define y3(x) (2 + (x) + pow((x), 2) - pow((x), 4) / 3.0 - pow((x), 5) / 15.0)

int main() {
    float x, x0, y0, y_first, y_second, y_third;

    // Input initial values of x and y
    printf("Enter initial values of x and y:\n");
    scanf("%f %f", &x0, &y0);

    // Input the x value at which the function is to be evaluated
    printf("Enter x at which function to be evaluated:\n");
    scanf("%f", &x);

    // Apply Picard's Method for successive approximations
    y_first = y0 + y1(x);     // First approximation
    y_second = y_first + y2(x); // Second approximation
    y_third = y_second + y3(x); // Third approximation

    // Display the results
    printf("\nPicard's Successive Approximations:\n");
    printf("First Approximation: y = %.4f\n", y_first);
    printf("Second Approximation: y = %.4f\n", y_second);
    printf("Third Approximation: y = %.4f\n", y_third);

    // Display final result
    printf("\nFinal Function Value at x = %.4f is %.4f\n", x, y_third);

    return 0;
}

