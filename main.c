#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <cassert>

const int INFINITE_ROOTS = -1;
const double EPS = 0.0000001;
const char CLEAN_SCREEN[] = "\e[1;1H\e[2J";
const char WRONG_INPUT_MESSAGE[] = "Некорректный ввод\n";

enum State {
    WORKING = 0,
    EQUATION_FAILED,
    INPUT_FAILED
};

enum NumberOfRoots {
    ZERO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS
};

bool compareTwoDoubles (double a, double b);
int solveEquation(double a, double b, double c, double* first_root, double* second_root);
bool isNan(double n);
bool isFinite(double n);


bool isNan(double n) {
    return n != n;
}

bool isFinite(double n) {
    if (isinf(n)) {
        return 0;
    }

    return !isNan(n);
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
    return (abs(a - b) < EPS);
}


int main() {
    printf(CLEAN_SCREEN);
    printf("Для решения уравнения вида ax^2 + bx + c = 0 введите по порядку все коэффициенты a, b, c\n");

    double first_coefficient = 0;
    double second_coefficient = 0;
    double third_coefficient = 0;

    printf("Введите первый коэффициент(a): ");
    if (scanf("%lf", &first_coefficient) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return INPUT_FAILED;
    }

    printf("Введите второй коэффициент(b): ");
    if (scanf("%lf", &second_coefficient) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return INPUT_FAILED;
    }

    printf("Введите третий коэффициент(c): ");
    if (scanf("%lf", &third_coefficient) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return INPUT_FAILED;
    }

    double first_root = 0;
    double second_root = 0;
    int number_of_roots = solveEquation(first_coefficient, second_coefficient, third_coefficient, &first_root, &second_root);

    switch (number_of_roots) {
        case 0:
            printf("Уравнение не имеет решений в действительных числах\n");
            break;

        case 1:
            printf("Уравнение имеет один корень: %lf\n", first_root);
            break;

        case 2:
            printf("Уравнение имеет два решения: %lf, %lf\n", first_root, second_root);
            break;

        case INFINITE_ROOTS:
            printf("Уравнение имеет бесконечное множество корней\n");
            break;

        default:
            printf("Что-то пошло не так...\n");
            return EQUATION_FAILED;

    }

    return WORKING;
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
//! @note   In case of infinite number of roots, returns INFINITE_ROOTS.
//------------------------------------------------------------------------

int solveEquation(double a, double b, double c, double* first_root, double* second_root) {

    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));

    assert (first_root != NULL);
    assert (second_root != NULL);
    assert (first_root != second_root);

    if (compareTwoDoubles(a, 0)) {
        if (compareTwoDoubles(b, 0)) {
            if (compareTwoDoubles(c, 0)) {
                return INFINITE_ROOTS;
            } else {
                return ZERO_ROOTS;
            }
        } else {
            *first_root = -c / b;
            return ONE_ROOT;
        }
    } else {
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return ZERO_ROOTS;
        }

        *first_root = (-b + sqrt(discriminant)) / (2 * a);

        if (compareTwoDoubles(discriminant, 0)) {
            return ONE_ROOT;
        }

        *second_root = (-b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOTS;
    }
}
