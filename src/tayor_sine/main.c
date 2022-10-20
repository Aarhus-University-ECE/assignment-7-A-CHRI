#include <stdio.h>
#include <math.h>
#include "taylor_sine.h"
#define PI 3.14159265358979323846

int main(void)
{
    double x[9] = {0.5, 0.5, 0.5 * PI, 0.5 * PI, 1.5 * PI, 1.5 * PI, 4.5 * PI, 4.5 * PI, 4.5 * PI};
    int n[9] = {2, 6, 2, 6, 2, 6, 2, 6, 15}; // Max terms is 6 since, 13! is too big for an integer.

    for (int i = 0; i < 9; i++)
    {
        printf("\nTaylor-sine function for %f, with %d terms: %f", x[i], n[i], taylor_sine(x[i], n[i]));
        printf("\nANSI C sine function for %f: %f\n", x[i], sin(x[i]));
    }
    /* Results: For higher values of x the result is much more volitile.
     * Generally the precision n will increase the accuracy of the result 
     */
    return 0;
}