#include "unit_test.h"

#include <stdio.h>

#include "solve_quadratic.h"
#include "helpful_functions.h"
#include "string_color.h"
#include "solve_quadratic.h"
#include "logger.h"

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

//--------------------------------------------------------------------------
//! Reads tests from input data
//!
//! @param [in] file_path  File path where tests located (look unit_test.h)
//!
//! @return number of tests passed
//--------------------------------------------------------------------------
static int readTestsFromFile(const char* file_path);


// global --------------------------------------------------------------------------------------------------------------

int runTestsFromFile(void)
{
    int test_passed = readTestsFromFile(UNIT_TESTS_FILE_PATH);

    writeLog(LogLevel_INFO, "Tests started, passed: %d\n", test_passed);
    return test_passed;
}


// static --------------------------------------------------------------------------------------------------------------

static int readTestsFromFile(const char* file_path)
{
    char test_line[SIZE_OF_BUFFER] = {0};
    int test_passed = 0;

    FILE* test_file = fopen(file_path, "r");

    if (!test_file)
    {
        fprintf(stderr, "File opening faild");
        return test_passed;
    }

    int    test_index               = 0;
    double first_coefficient        = 0;
    double second_coefficient       = 0;
    double third_coefficient        = 0;
    double expected_first_root      = 0;
    double expected_second_root     = 0;
    int    expected_number_of_roots = 0;

    while ((fscanf(test_file, "%[^\n]", test_line)) != EOF)
    {
        fgetc(test_file);

        sscanf(test_line,
               "%d %lf %lf %lf %lf %lf %d",
               &test_index,
               &first_coefficient,
               &second_coefficient,
               &third_coefficient,
               &expected_first_root,
               &expected_second_root,
               &expected_number_of_roots);

        TestData current_test = {
            .test_index               = test_index,
            .input_coefficients       = {
                                            first_coefficient,
                                            second_coefficient,
                                            third_coefficient,
                                        },
            .expected_first_root      = expected_first_root,
            .expected_second_root     = expected_second_root,
            .expected_number_of_roots = expected_number_of_roots,

        };

        Tests result = makeTest(current_test);

        if (result == Tests_WORKING)
        {
            test_passed++;
        }
    }

    fclose(test_file);

    return test_passed;
}

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
