#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "constants.h"

typedef enum Tests {
    Tests_WORKING   = 1,
    Tests_TEST_FAIL = 0,
} Tests;

typedef struct TestData {
    int number_of_test;
    Coefficients input_coefficients;
    double expected_first_root;
    double expected_second_root;
    int expected_number_of_roots;
} TestData;

int runTests();
Tests makeTest(TestData);

#endif // UNIT_TEST_H
