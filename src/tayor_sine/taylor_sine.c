#include "taylor_sine.h"
#include <math.h>
#include <assert.h>

double fact(double x)
{
    /* Pre: Non-negative integer */
    assert(x > 0);

    /* Post: Recursively compute the factorial of x */
    if (x == 1)
        return 1;
    return x * fact(x - 1);
}

double taylor_sine(double x, int n)
{
    /* Pre: Terms n, is a positive integer, but no greater than 12 */
    assert(n > 0);

    /* Post: Compute the taylor value of sine */
    double r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            r -= pow(x, 2 * i - 1) / fact(2 * i - 1);
        else
            r += pow(x, 2 * i - 1) / fact(2 * i - 1);
    }
    return r;
}