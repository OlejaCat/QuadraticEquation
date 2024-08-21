#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <cmath>
#include <cassert>
#include <string.h>

const double EPS = 0.0000001;
const char CLEAR_SCREEN[] = "\e[1;1H\e[2J";
const char WRONG_INPUT_MESSAGE[] = "Некорректный ввод. Попробуйте снова\n";
const char SOMETHING_WENT_WRONG[] = "Что-то пошло не так\n";

enum State {
    State_WORKING         = 0,
    State_EQUATION_FAILED = 1,
    State_INPUT_FAILED    = 2,
    State_TEST_FAIL       = 3,
};

enum Tests {
    Tests_WORKING   = 1,
    Tests_TEST_FAIL = 0,
};

enum NumberOfRoots {
    NumberOfRoots_INFINITE_ROOTS = -1,
    NumberOfRoots_ZERO_ROOTS     =  0,
    NumberOfRoots_ONE_ROOT       =  1,
    NumberOfRoots_TWO_ROOTS      =  2,
};


bool isNan(double n);
bool isInf(double n);
bool isFinite(double n);
bool compareTwoDoubles (double a, double b);
void swap(double* a, double* b);
void clearScreen();
int runTests();
enum NumberOfRoots solveEquation(double a,
                             double b,
                             double c,
                             double* first_root,
                             double* second_root);
enum State getCoefficients(double* a, double* b, double* c);
enum State printRoots(int number_of_roots, double first_root, double second_root);
enum Tests makeTest(int number_of_tests,
             double first_coefficient,
             double second_coefficient,
             double third_coefficient,
             double expected_first_root,
             double expected_second_root,
             int expected_number_of_roots);
enum NumberOfRoots LinearEquation(double first_coefficient,
                             double second_coefficient,
                             double* first_root);
enum NumberOfRoots quadraticEquation(double a,
                             double b,
                             double c,
                             double* first_root,
                             double* second_root);


int main() {
    runTests();

    printf("Чтобы выйти из программы введите `q`, чтобы решить квадратку введите `s`\n");

    char user_input[30] = {0};

    while (true) {
        printf("eq:");
        scanf("%s", &user_input);
        if (strcmp(user_input, "quit") == 0 || strcmp(user_input, "q") == 0) {
            break;
        } else if (strcmp(user_input, "solve") == 0 || strcmp(user_input, "s") == 0) {
            double first_coefficient = 0;
            double second_coefficient = 0;
            double third_coefficient = 0;

            enum State exit_code_input = getCoefficients(&first_coefficient, &second_coefficient, &third_coefficient);

            if (exit_code_input == State_INPUT_FAILED) {
                continue;
            }

            double first_root = 0;
            double second_root = 0;
            enum NumberOfRoots number_of_roots = solveEquation(first_coefficient,
                                         second_coefficient,
                                         third_coefficient,
                                         &first_root,
                                         &second_root);

            printRoots(number_of_roots, first_root, second_root);
        } else {
            printf("Неизвестная команда\n");
        }
    }
    return State_WORKING;
}


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
//! @return True if a is greater than b and False if a is less than b
//-----------------------------------------------------------------------
bool compareTwoDoubles (double a, double b) {
    return (fabs(a - b) < EPS);
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


//--------------------------------------------------------------------------
//! Gets coefficients of quadratic equation
//!
//! @param [out] a First coefficient
//! @param [out] b Second coefficient
//! @param [out] c Third coefficient
//!
//! @return State_WORKING if input correct and State_EQUATION_FAILED if not
//--------------------------------------------------------------------------
enum State getCoefficients(double* a, double* b, double* c) {
    assert (isFinite(*a));
    assert (isFinite(*b));
    assert (isFinite(*c));

    clearScreen();
    printf("Для решения уравнения вида ax^2 + bx + c = 0 введите по порядку все коэффициенты a, b, c\n");

    printf("Введите первый коэффициент(a): ");
    if (scanf("%lf", a) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    printf("Введите второй коэффициент(b): ");
    if (scanf("%lf", b) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    printf("Введите третий коэффициент(c): ");
    if (scanf("%lf", c) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    return State_WORKING;
}


//-------------------------------------------------------------------------------
//! Makes output of roots
//!
//! @param [in] number_of_roots
//! @param [in]      first_root
//! @param [in]     second_root
//!
//! @return State_WORKING if everething OK and State_EQUATION_FAILED if not OK
//-------------------------------------------------------------------------------
enum State printRoots(int number_of_roots, double first_root, double second_root) {

    assert (isFinite(number_of_roots));
    assert (isFinite(first_root));
    assert (isFinite(second_root));

    switch (number_of_roots) {
        case 0:
            printf("Уравнение не имеет решений в действительных числах\n");
            return State_WORKING;

        case 1:
            printf("Уравнение имеет один корень: %lf\n", first_root);
            return State_WORKING;

        case 2:
            printf("Уравнение имеет два решения: %lf, %lf\n", first_root, second_root);
            return State_WORKING;

        case NumberOfRoots_INFINITE_ROOTS:
            printf("Уравнение имеет бесконечное множество корней\n");
            return State_WORKING;

        default:
            printf("Что-то пошло не так...\n");
            return State_EQUATION_FAILED;

    }
}


//-----------------------------------------------------------------------
//!Solves a square equation ax^2 + bx + c = 0
//!
//! @param [in]   a            Fisrt coefficient
//! @param [in]   b            Second coefficient
//! @param [in]   c            Third coefficient
//! @param [out]  first_root   Pointer to the 1st root
//! @param [out]  second_root  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note  uses quadratic and linear equations to solve
//------------------------------------------------------------------------
enum NumberOfRoots solveEquation(double a,
                             double b,
                             double c,
                             double* first_root,
                             double* second_root)
{
    assert (isFinite(a));
    assert (isFinite(b));
    assert (isFinite(c));

    assert (first_root != NULL);
    assert (second_root != NULL);
    assert (first_root != second_root);

    if (compareTwoDoubles(a, 0)) {
        return LinearEquation(b, c, first_root);
    } else {
        return quadraticEquation(a, b, c, first_root, second_root);
    }
}


//-----------------------------------------------------------------------
//!Solves a square equation ax^2 + bx + c = 0 where a != 0
//!
//! @param [in]   a               Fisrt coefficient
//! @param [in]   b               Second coefficient
//! @param [in]   c               Third coefficient
//! @param [out]  first_root      Pointer to the 1st root
//! @param [out]  second_root     Pointer to the 2nd root
//!
//! @return Number of roots
//-----------------------------------------------------------------------
enum NumberOfRoots quadraticEquation(double a,
                             double b,
                             double c,
                             double* first_root,
                             double* second_root)
{
    double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return NumberOfRoots_ZERO_ROOTS;
        }

        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);

        if (x2 < x1) {
            swap(&x1, &x2);
        }

        *second_root = x2;
        *first_root = x1;

        if (compareTwoDoubles(discriminant, 0)) {
            return NumberOfRoots_ONE_ROOT;
        }

        return NumberOfRoots_TWO_ROOTS;
}


//-----------------------------------------------------------------------
//!Solves a square equation ax + b = 0
//!
//! @param [in]   first_coefficient    Fisrt coefficient
//! @param [in]   second_coefficient   Second coefficient
//! @param [out]  first_root           Pointer to the 1st root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots, returns INFINITE_ROOTS.
//------------------------------------------------------------------------
enum NumberOfRoots LinearEquation(double first_coefficient,
                             double second_coefficient,
                             double* first_root)
{
    if (compareTwoDoubles(first_coefficient, 0)) {
        if (compareTwoDoubles(second_coefficient, 0)) {
            return NumberOfRoots_INFINITE_ROOTS;
        } else {
            return NumberOfRoots_ZERO_ROOTS;
        }
    } else {
        *first_root = -second_coefficient / first_coefficient;
        return NumberOfRoots_ONE_ROOT;
    }
}


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

