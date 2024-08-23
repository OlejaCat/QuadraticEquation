#include "../include/solve_quadratic.h"

#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "../include/constants.h"
#include "../include/helpful_functions.h"


//-----------------------------------------------------------------------
//!Solves a square equation ax^2 + bx + c = 0
//!
//! @param [in]   a            Fisrt coefficient
//! @param [in]   b            Second coefficient
//! @param [in]   c            Third coefficient
//! @param [out]  first_root   Pointer to the 1st root
//! @param [out]  second_root  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note  uses quadratic and linear equations to solve
//------------------------------------------------------------------------
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


//-----------------------------------------------------------------------
//!Solves a square equation ax^2 + bx + c = 0 where a != 0
//!
//! @param [in]   a               Fisrt coefficient
//! @param [in]   b               Second coefficient
//! @param [in]   c               Third coefficient
//! @param [out]  first_root      Pointer to the 1st root
//! @param [out]  second_root     Pointer to the 2nd root
//!
//! @return Number of roots
//-----------------------------------------------------------------------
NumberOfRoots quadraticEquation(double a,
                                double b,
                                double c,
                                double* first_root,
                                double* second_root)
{
    assertStrict (isFinite(a));
    assertStrict (isFinite(b));
    assertStrict (isFinite(c));

    double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
        {
            return NumberOfRoots_ZERO_ROOTS;
        }

        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);

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


//-----------------------------------------------------------------------
//!Solves a square equation ax + b = 0
//!
//! @param [in]   a                    Fisrt coefficient
//! @param [in]   b                    Second coefficient
//! @param [out]  first_root           Pointer to the 1st root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots, returns INFINITE_ROOTS.
//------------------------------------------------------------------------
NumberOfRoots LinearEquation(double a,
                             double b,
                             double* first_root)
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
