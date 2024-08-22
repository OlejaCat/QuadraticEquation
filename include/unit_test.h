enum Tests {
    Tests_WORKING   = 1,
    Tests_TEST_FAIL = 0,
};

typedef struct test_data {
    int number_of_test;
    Coefficients input_coefficients;
    double expected_first_root;
    double expected_second_root;
    int expected_number_of_roots;
} TestData;

int runTests();
enum Tests makeTest(TestData);
