#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <cassert>

const int INFINITE_ROOTS = -1;
const double EPS = 0.0000001;

bool compareTwoDoubles (double a, double b);
int solveEquation(double a, double b, double c, double* first_root, double* second_root);


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
    double first_coefficient = 0, second_coefficient = 0, third_coefficient = 0;

    printf("\e[1;1H\e[2J");
    printf("Для решения уравнения вида ax^2 + bx + c = 0 введите по порядку все коэффициенты a, b, c\n");

    printf("Введите первый коэффициент(a): ");
    scanf("%lf", &first_coefficient);

    printf("Введите второй коэффициент(b): ");
    scanf("%lf", &second_coefficient);

    printf("Введите третий коэффициент(c): ");
    scanf("%lf", &third_coefficient);

    double first_root = 0, second_root = 0;
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
            return 1;
    }

    return 0;
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

                return 0;

            }

        } else {

            *first_root = -c / b;
            return 1;

        }

    } else {

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return 0;
        }

        *first_root = (-b + sqrt(discriminant)) / (2 * a);

        if (compareTwoDoubles(discriminant, 0)) {
            return 1;
        }

        *second_root = (-b - sqrt(discriminant)) / (2 * a);
        return 2;

    }
}
