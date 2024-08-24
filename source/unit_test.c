#include "unit_test.h"

#include <stdio.h>

#include "constants.h"
#include "solve_quadratic.h"
#include "helpful_functions.h"
#include "string_color.h"


Tests makeTest(const TestData input_data)
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
               input_data.number_of_test,
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

    printf(BOLD_GREEN "Test %d passed\n", input_data.number_of_test);
    return Tests_WORKING;
}


int runTests(void)
{
    TestData tests[8] = {
        // 1
        {
            .number_of_test                        =  1,
            .input_coefficients                    =  {0, 0, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_INFINITE_ROOTS,
        },
        // 2
        {
            .number_of_test                        =  2,
            .input_coefficients                    =  {0, 0, 1},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ZERO_ROOTS,
        },
        // 3
        {
            .number_of_test                        =  3,
            .input_coefficients                    =  {0, 10, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
        },
        // 4
        {
            .number_of_test                        =  4,
            .input_coefficients                    =  {0, 10, 5},
            .expected_first_root                   =  -0.5,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
        },
        // 5
        {
            .number_of_test                        =  5,
            .input_coefficients                    =  {10, 0, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  0,
            .expected_number_of_roots              =  NumberOfRoots_ONE_ROOT,
        },
        // 6
        {
            .number_of_test                        =  6,
            .input_coefficients                    =  {4, 0, -16},
            .expected_first_root                   = -2,
            .expected_second_root                  =  2,
            .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
        },
        // 7
        {
            .number_of_test                        =  7,
            .input_coefficients                    =  {5, -5, 0},
            .expected_first_root                   =  0,
            .expected_second_root                  =  1,
            .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
        },
        // 8
        {
            .number_of_test                        =  8,
            .input_coefficients                    =  {1, -3, 2},
            .expected_first_root                   =  1,
            .expected_second_root                  =  2,
            .expected_number_of_roots              =  NumberOfRoots_TWO_ROOTS,
        }
    };

    unsigned test_passed = 0;

    int number_of_tests = SIZE_OF_ARRAY(tests);
    for (int number_of_test = 0; number_of_test < number_of_tests; number_of_test++)
    {
        test_passed += makeTest(tests[number_of_test]);
    }

    return (int) test_passed;
}
