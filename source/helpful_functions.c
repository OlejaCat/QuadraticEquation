#include "../include/helpful_functions.h"

#include <math.h>
#include <stdio.h>

#include "../include/constants.h"


//----------------
//! Cleans screen
//----------------
void clearScreen() {
    printf(CLEAR_SCREEN);
}


//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if a is equal to b and False if a is not equal to b
//-----------------------------------------------------------------------
bool equatTwoDoubles (double a, double b) {
    return (fabs(a - b) < EPS);
}

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if a is greater than b and False if a is less than b
//-----------------------------------------------------------------------
bool compareGreaterTwoDoubles (double a, double b) {
    return (a - b > EPS);
}

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if b is greater than a and False if b is less than a
//-----------------------------------------------------------------------
bool compareLesserTwoDoubles (double a, double b) {
    return (b - a > EPS);
}

//--------------------------------------
//! Swaps two numbers in double format
//!
//! @param [out] a First double number
//! @param [out] b Second double number
//--------------------------------------
void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}


//------------------------------------------------------
//! Checks if number is negative or positive infinity
//!
//! @param [in] n double number
//!
//! @return True or False
//------------------------------------------------------
bool isInf(double n) {
    return n == INFINITY || n == -INFINITY;
}


//----------------------------
//! Checks if number is NaN
//!
//! @param [in] n double number
//!
//! @return True or False
//----------------------------
bool isNan(double n) {
    return n != n;
}


//-----------------------------
//! Checks if number is finite
//!
//! @param [in] n double number
//!
//! @return True or False
//-----------------------------
bool isFinite(double n) {
    if (isInf(n)) {
        return 0;
    }

    return !isNan(n);
}
