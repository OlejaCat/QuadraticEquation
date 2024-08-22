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
enum Tests makeTest(int number_of_tests,
             double first_coefficient,
             double second_coefficient,
             double third_coefficient,
             double expected_first_root,
             double expected_second_root,
             int expected_number_of_roots)
{
    double first_root = 0;
    double second_root = 0;

    enum NumberOfRoots number_of_roots = solveEquation(first_coefficient,
                                             second_coefficient,
                                             third_coefficient,
                                             &first_root,
                                             &second_root);
    if (!compareTwoDoubles(first_root, expected_first_root)
        || !compareTwoDoubles(second_root, expected_second_root)
        || !compareTwoDoubles(number_of_roots, expected_number_of_roots))
    {
        printf("Error on test %d. Input a: %lf, b: %lf, c: %lf\n",
               number_of_tests,
               first_coefficient,
               second_coefficient,
               third_coefficient);
        printf("Expected first root: %lf, second root: %lf, number of roots: %d\n",
               expected_first_root,
               expected_second_root,
               expected_number_of_roots);
        printf("Got first root: %lf, second root: %lf, number of roots: %d\n",
               first_root,
               second_root,
               number_of_roots);
        return Tests_TEST_FAIL;
    }
    printf("Test %d passed\n", number_of_tests);
    return Tests_WORKING;
}


//------------------
//! Runs some tests
//------------------
int runTests()
{
    int test_passed = 0;
    test_passed += makeTest(1, 0,  0,  0,   0,   0, NumberOfRoots_INFINITE_ROOTS);
    test_passed += makeTest(2, 0,  0,  1,   0,   7, NumberOfRoots_ZERO_ROOTS);
    test_passed += makeTest(3, 0,  10, 0,   0,   0, NumberOfRoots_ONE_ROOT);
    test_passed += makeTest(4, 0,  10, 5,  -0.5, 0, NumberOfRoots_ONE_ROOT);
    test_passed += makeTest(5, 10, 0,  0,   0,   0, NumberOfRoots_ONE_ROOT);
    test_passed += makeTest(6, 4,  0, -16, -2,   2, NumberOfRoots_TWO_ROOTS);
    test_passed += makeTest(7, 5, -5,  0,   0,   1, NumberOfRoots_TWO_ROOTS);
    test_passed += makeTest(8, 1, -3,  2,   1,   2, NumberOfRoots_TWO_ROOTS);
    return test_passed;
}
