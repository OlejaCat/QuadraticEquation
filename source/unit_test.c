#include "unit_test.h"

#include <stdio.h>

#include "solve_quadratic.h"
#include "helpful_functions.h"
#include "string_color.h"
#include "solve_quadratic.h"

typedef enum Tests
{
    Tests_WORKING   = 1,
    Tests_TEST_FAIL = 0,
} Tests;

typedef struct TestData
{
    int          test_index;
    Coefficients input_coefficients;
    double       expected_first_root;
    double       expected_second_root;
    int          expected_number_of_roots;
} TestData;

// static --------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------
//! Checks if quadration equation is correct
//!
//! @param [in] input_data  Data to test
//!
//! @return State_TEST_FAIL or State_WORKING
//-------------------------------------------------------------------------
static Tests makeTest(TestData input_data);

// global --------------------------------------------------------------------------------------------------------------

int runTests(void)
{
    TestData tests[8] = {
        // 1
        {
            .test_index                            =  1,
            .input_coefficients                    =  {0, 0, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_INFINITE_ROOTS,
        },
        // 2
        {
            .test_index                            =  2,
            .input_coefficients                    =  {0, 0, 1},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ZERO_ROOTS,
        },
        // 3
        {
            .test_index                            =  3,
            .input_coefficients                    =  {0, 10, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
        },
        // 4
        {
            .test_index                            =  4,
            .input_coefficients                    =  {0, 10, 5},
            .expected_first_root                   =  -0.5,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
        },
        // 5
        {
            .test_index                            =  5,
            .input_coefficients                    =  {10, 0, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
        },
        // 6
        {
            .test_index                            =  6,
            .input_coefficients                    =  {4, 0, -16},
            .expected_first_root                   = -2,
            .expected_second_root                  =  2,
            .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
        },
        // 7
        {
            .test_index                            =  7,
            .input_coefficients                    =  {5, -5, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  1,
            .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
        },
        // 8
        {
            .test_index                            =  8,
            .input_coefficients                    =  {1, -3, 2},
            .expected_first_root                   =  1,
            .expected_second_root                  =  2,
            .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
        }
    };

    unsigned test_passed = 0;

    int number_of_tests = SIZE_OF_ARRAY(tests);
    for (int test_index = 0; test_index < number_of_tests; test_index++)
    {
        test_passed += makeTest(tests[test_index]);
    }

    return (int) test_passed;
}

// static --------------------------------------------------------------------------------------------------------------

static Tests makeTest(const TestData input_data)
{
    double first_root = 0;
    double second_root = 0;

    NumberOfRoots number_of_roots = solveEquation(input_data.input_coefficients,
                                                  &first_root,
                                                  &second_root);

    if (   !equatTwoDoubles(first_root,      input_data.expected_first_root)
        || !equatTwoDoubles(second_root,     input_data.expected_second_root)
        || !equatTwoDoubles(number_of_roots, input_data.expected_number_of_roots))
    {
        printf(BOLD_RED "Test %d failed\n\tInput a: %g, b: %g, c: %g\n",
               input_data.test_index,
               input_data.input_coefficients.first_coefficient,
               input_data.input_coefficients.second_coefficient,
               input_data.input_coefficients.third_coefficient);
        printf(BOLD_RED "\tExpected first root: %g, second root: %g, number of roots: %d\n",
               input_data.expected_first_root,
               input_data.expected_second_root,
               input_data.expected_number_of_roots);
        printf(BOLD_RED "\tGot first root: %g, second root: %g, number of roots: %d\n",
               first_root,
               second_root,
               number_of_roots);
        return Tests_TEST_FAIL;
    }

    printf(BOLD_GREEN "Test %d passed\n", input_data.test_index);
    return Tests_WORKING;
}
