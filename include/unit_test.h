enum Tests {
    Tests_WORKING   = 1,
    Tests_TEST_FAIL = 0,
};


int runTests();
enum Tests makeTest(int number_of_tests,
             double first_coefficient,
             double second_coefficient,
             double third_coefficient,
             double expected_first_root,
             double expected_second_root,
             int expected_number_of_roots);
