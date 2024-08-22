#include <cassert>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "../include/constants.h"
#include "../include/solve_quadratic.h"
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
enum NumberOfRoots solveEquation(double a,
                             double b,
                             double c,
                             double* first_root,
                             double* second_root)
{
    assert (isFinite(a));
    assert (isFinite(b));
    assert (isFinite(c));

    assert (first_root != NULL);
    assert (second_root != NULL);
    assert (first_root != second_root);

    if (compareTwoDoubles(a, 0)) {
        return LinearEquation(b, c, first_root);
    } else {
        return quadraticEquation(a, b, c, first_root, second_root);
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
enum NumberOfRoots quadraticEquation(double a,
                             double b,
                             double c,
                             double* first_root,
                             double* second_root)
{
    double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return NumberOfRoots_ZERO_ROOTS;
        }

        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);

        if (x2 < x1) {
            swap(&x1, &x2);
        }

        *second_root = x2;
        *first_root = x1;

        if (compareTwoDoubles(discriminant, 0)) {
            return NumberOfRoots_ONE_ROOT;
        }

        return NumberOfRoots_TWO_ROOTS;
}


//-----------------------------------------------------------------------
//!Solves a square equation ax + b = 0
//!
//! @param [in]   first_coefficient    Fisrt coefficient
//! @param [in]   second_coefficient   Second coefficient
//! @param [out]  first_root           Pointer to the 1st root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots, returns INFINITE_ROOTS.
//------------------------------------------------------------------------
enum NumberOfRoots LinearEquation(double first_coefficient,
                             double second_coefficient,
                             double* first_root)
{
    if (compareTwoDoubles(first_coefficient, 0)) {
        if (compareTwoDoubles(second_coefficient, 0)) {
            return NumberOfRoots_INFINITE_ROOTS;
        } else {
            return NumberOfRoots_ZERO_ROOTS;
        }
    } else {
        *first_root = -second_coefficient / first_coefficient;
        return NumberOfRoots_ONE_ROOT;
    }
}
