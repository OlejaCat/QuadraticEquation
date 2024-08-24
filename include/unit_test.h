#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "constants.h"
#include "solve_quadratic.h"

typedef enum Tests
{
    Tests_WORKING   = 1,
    Tests_TEST_FAIL = 0,
} Tests;

typedef struct TestData
{
    int          number_of_test;
    Coefficients input_coefficients;
    double       expected_first_root;
    double       expected_second_root;
    int          expected_number_of_roots;
} TestData;

//------------------
//! Runs some tests
//------------------
int runTests(void);

//-------------------------------------------------------------------------
//! Checks if quadration equation is correct
//!
//! @param [in] input_data  Data to test
//!
//! @return State_TEST_FAIL or State_WORKING
//-------------------------------------------------------------------------
Tests makeTest(TestData input_data);

#endif // UNIT_TEST_H
