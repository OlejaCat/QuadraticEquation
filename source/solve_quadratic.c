#include "solve_quadratic.h"

#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "helpful_functions.h"


NumberOfRoots solveEquation(Coefficients user_input,
                            double* first_root,
                            double* second_root)
{
    assertStrict (isFinite(user_input.first_coefficient));
    assertStrict (isFinite(user_input.second_coefficient));
    assertStrict (isFinite(user_input.third_coefficient));

    assertStrict (first_root  != NULL);
    assertStrict (second_root != NULL);
    assertStrict (first_root  != second_root);

    if (equatTwoDoubles(user_input.first_coefficient, 0))
    {
        return LinearEquation(user_input.second_coefficient,
                              user_input.third_coefficient,
                              first_root);
    }
    else
    {
        return quadraticEquation(user_input.first_coefficient,
                                 user_input.second_coefficient,
                                 user_input.third_coefficient,
                                 first_root, second_root);
    }
}


NumberOfRoots quadraticEquation(const double a,
                                const double b,
                                const double c,
                                double*      first_root,
                                double*      second_root)
{
    assertStrict (isFinite(a));
    assertStrict (isFinite(b));
    assertStrict (isFinite(c));

    const double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
    {
        return NumberOfRoots_ZERO_ROOTS;
    }

    double sqrt_discriminant = sqrt(discriminant);

    double x1 = (-b - sqrt_discriminant) / (2 * a);
    double x2 = (-b + sqrt_discriminant) / (2 * a);

    x1 = equatTwoDoubles(x1, 0) ? fabs(x1) : x1;
    x2 = equatTwoDoubles(x2, 0) ? fabs(x2) : x2;

    if (x2 < x1)
    {
        swap(&x1, &x2, sizeof(double));
    }

    *second_root = x2;
    *first_root = x1;

    if (equatTwoDoubles(discriminant, 0))
    {
        return NumberOfRoots_ONE_ROOT;
    }

    return NumberOfRoots_TWO_ROOTS;
}


NumberOfRoots LinearEquation(const double a,
                             const double b,
                             double*      first_root)
{
    assertStrict (isFinite(a));
    assertStrict (isFinite(b));

    if (equatTwoDoubles(a, 0))
    {
        if (equatTwoDoubles(b, 0))
        {
            return NumberOfRoots_INFINITE_ROOTS;
        }
        else
        {
            return NumberOfRoots_ZERO_ROOTS;
        }
    } else {
        *first_root = -b / a;
        return NumberOfRoots_ONE_ROOT;
    }
}
