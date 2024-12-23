#include <stdio.h>
#include <math.h>

#define f1(x, y, z) (z)
#define f2(x, y, z) 6 * (x)

int main()
{
    float xa, xb, ya, yb, x0, y0, z0, x, y, z, xp, h, sol, ny, nz, error, E, g[3], v[3], gs;
    int i;

    // Input the boundary conditions
    printf("Enter Boundary Conditions (xa, ya, xb, yb)\n");
    scanf("%f%f%f%f", &xa, &ya, &xb, &yb);

    // Input x at which the value is required
    printf("Enter x at which value is required\n");
    scanf("%f", &xp);

    // Input step size
    printf("Enter the step size\n");
    scanf("%f", &h);

    // Input accuracy limit
    printf("Enter accuracy limit\n");
    scanf("%f", &E);

    x = xa;
    y = ya;
    g[0] = z = (yb - ya) / (xb - xa);
    printf("g[0] = %f\n", g[0]);

    // Using Euler's method
    while (x < xb)
    {
        ny = y + (f1(x, y, z)) * h;
        nz = z + (f2(x, y, z)) * h;
        x = x + h;
        y = ny;
        z = nz;

        if (fabs(x - xp) < h)  // Use a tolerance for floating-point comparison
            sol = y;
    }
    v[0] = y;

    if (y < yb)
        g[1] = z = 2 * g[0];
    else
        g[1] = z = 0.5 * g[0];

    printf("g[1] = %f\n", g[1]);

    // Using Euler's method again
    x = xa;
    y = ya;
    z = g[1];

    while (x < xb)
    {
        ny = y + (f1(x, y, z)) * h;
        nz = z + (f2(x, y, z)) * h;
        x = x + h;
        y = ny;
        z = nz;

        if (fabs(x - xp) < h)  // Use a tolerance for floating-point comparison
            sol = y;
    }

    while (1)
    {
        x = xa;
        y = ya;
        gs = z = g[1] - (v[1] - yb) / (v[1] - v[0]) * (g[1] - g[0]);

        while (x < xb)
        {
            ny = y + (f1(x, y, z)) * h;
            nz = z + (f2(x, y, z)) * h;
            x = x + h;
            y = ny;
            z = nz;

            if (fabs(x - xp) < h)  // Use a tolerance for floating-point comparison
                sol = y;
        }

        error = fabs(y - yb) / y;
        v[0] = v[1];
        v[1] = y;
        g[0] = g[1];
        g[1] = gs;

        if (error < E)
        {
            printf("y(%f) = %f\n", xp, sol);
            break;
        }
    }

    return 0;
}

