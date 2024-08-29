#ifndef SOLVE_QUADRATIC_H
#define SOLVE_QUADRATIC_H

typedef struct Coefficients
{
    double first_coefficient;
    double second_coefficient;
    double third_coefficient;
} Coefficients;

typedef enum NumberOfRoots
{
    NumberOfRoots_INFINITE_ROOTS = -1,
    NumberOfRoots_ZERO_ROOTS     =  0,
    NumberOfRoots_ONE_ROOT       =  1,
    NumberOfRoots_TWO_ROOTS      =  2,
} NumberOfRoots;

//-----------------------------------------------------------------------
//!Solves a square equation ax^2 + bx + c = 0
//!
//! @param [in]   user_input   Coefficients of square equation
//! @param [out]  first_root     Pointer to the 1st root
//! @param [out]  second_root    Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note  uses quadratic and linear equations to solve
//------------------------------------------------------------------------
NumberOfRoots solveEquation(Coefficients user_input,
                            double* first_root,
                            double* second_root);

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
NumberOfRoots linearEquation(double  a,
                             double  b,
                             double* first_root);

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
NumberOfRoots quadraticEquation(double  a,
                                double  b,
                                double  c,
                                double* first_root,
                                double* second_root);

#endif // SOLVE_QUDRATIC_H
