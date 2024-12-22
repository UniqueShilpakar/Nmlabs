#include <stdio.h>
#include <math.h>

/* Equations:
   x = (17 - y + 2z) / 20
   y = (-18 - 3x + z) / 20
   z = (25 - 2x + 3y) / 20
*/
#define f1(x, y, z)  ((17 - y + 2 * z) / 20)
#define f2(x, y, z)  ((-18 - 3 * x + z) / 20)
#define f3(x, y, z)  ((25 - 2 * x + 3 * y) / 20)

int main() {
    float x0 = 0, y0 = 0, z0 = 0; // Initial guesses
    float x1, y1, z1;             // Updated values
    float e1, e2, e3;             // Errors
    float e;                      // Tolerable error
    int count = 1;                // Iteration count

    // Input tolerable error
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    if (e <= 0) {
        printf("Error: Tolerable error must be positive.\n");
        return 1;
    }

    // Iteration process
    printf("\nIteration\tx\t\ty\t\tz\n");
    printf("--------------------------------------------------\n");
    do {
        /* Calculate next values */
        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0);
        z1 = f3(x0, y0, z0);

        /* Print current iteration values */
        printf("%d\t\t%.4f\t%.4f\t%.4f\n", count, x1, y1, z1);

        /* Compute errors */
        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);

        /* Update variables for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;

        count++;
    } while (e1 > e || e2 > e || e3 > e);

    // Print solution
    printf("\nSolution: x = %.3f, y = %.3f, z = %.3f\n", x1, y1, z1);

    return 0;
}

