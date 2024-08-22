#include <stdio.h>
#include "../include/constants.h"
#include "../include/solve_quadratic.h"
#include "../include/helpful_functions.h"
#include "../include/unit_test.h"


//-------------------------------------------------------------------------
//! Checks if quadration equation is correct
//!
//! @param [in] number_of_tests           Number of test
//! @param [in] first_coefficient         Fisrt coefficient
//! @param [in] second_coefficient        Second coefficient
//! @param [in] third_coefficient         Third coefficient
//! @param [in] expected_first_root       First root that is expected
//! @param [in] expected_second_root      Second root that is expected
//! @param [in] expected_number_of_roots  Number of roots that is expected
//!
//! @return State_TEST_FAIL or State_WORKING
//-------------------------------------------------------------------------
enum Tests makeTest(TestData input_data)
{
    double first_root = 0;
    double second_root = 0;

    enum NumberOfRoots number_of_roots = solveEquation(input_data.input_coefficients,
                                             &first_root,
                                             &second_root);
    if (!compareTwoDoubles(first_root, input_data.expected_first_root)
        || !compareTwoDoubles(second_root, input_data.expected_second_root)
        || !compareTwoDoubles(number_of_roots, input_data.expected_number_of_roots))
    {
        printf("Error on test struct %d. Input a: %lf, b: %lf, c: %lf\n",
               input_data.number_of_test,
               input_data.input_coefficients.first_coefficient,
               input_data.input_coefficients.second_coefficient,
               input_data.input_coefficients.third_coefficient);
        printf("Expected first root: %lf, second root: %lf, number of roots: %d\n",
               input_data.expected_first_root,
               input_data.expected_second_root,
               input_data.expected_number_of_roots);
        printf("Got first root: %lf, second root: %lf, number of roots: %d\n",
               first_root,
               second_root,
               number_of_roots);
        return Tests_TEST_FAIL;
    }
    printf("Test %d passed\n", input_data.number_of_test);
    return Tests_WORKING;
}


//------------------
//! Runs some tests
//------------------
int runTests()
{
    TestData test1 = {
        .number_of_test                        =  1,
        .input_coefficients                    =  {0, 0, 0},
        .expected_first_root                   =  0,
        .expected_second_root                  =  0,
        .expected_number_of_roots              =  NumberOfRoots_INFINITE_ROOTS,
    };

    TestData test2 = {
        .number_of_test                        =  2,
        .input_coefficients                    =  {0, 0, 1},
        .expected_first_root                   =  0,
        .expected_second_root                  =  0,
        .expected_number_of_roots              =  NumberOfRoots_ZERO_ROOTS,
    };

    TestData test3 = {
        .number_of_test                        =  3,
        .input_coefficients                    =  {0, 10, 0},
        .expected_first_root                   =  0,
        .expected_second_root                  =  0,
        .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
    };

    TestData test4 = {
        .number_of_test                        =  4,
        .input_coefficients                    =  {0, 10, 5},
        .expected_first_root                   =  -0.5,
        .expected_second_root                  =  0,
        .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
    };

    TestData test5 = {
        .number_of_test                        =  5,
        .input_coefficients                    =  {10, 0, 0},
        .expected_first_root                   =  0,
        .expected_second_root                  =  0,
        .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
    };

    TestData test6 = {
        .number_of_test                        =  6,
        .input_coefficients                    =  {4, 0, -16},
        .expected_first_root                   = -2,
        .expected_second_root                  =  2,
        .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
    };

    TestData test7 = {
        .number_of_test                        =  7,
        .input_coefficients                    =  {5, -5, 0},
        .expected_first_root                   =  0,
        .expected_second_root                  =  1,
        .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
    };

    TestData test8 = {
        .number_of_test                        =  8,
        .input_coefficients                    =  {1, -3, 2},
        .expected_first_root                   =  1,
        .expected_second_root                  =  2,
        .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
    };

    TestData tests[8] = {test1, test2, test3,
                        test4, test5, test6,
                        test7, test8};

    int test_passed = 0;

    int number_of_tests = sizeof(tests)/sizeof(tests[0]);
    for (int number_of_test = 0; number_of_test < number_of_tests; number_of_test++) {
        test_passed += makeTest(tests[number_of_test]);
    }
    return test_passed;
}
