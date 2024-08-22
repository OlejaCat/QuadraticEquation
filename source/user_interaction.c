#include <stdio.h>
#include <assert.h>
#include "../include/user_interaction.h"
#include "../include/solve_quadratic.h"
#include "../include/helpful_functions.h"
#include "../include/constants.h"


//--------------------------------------------------------------------------
//! Gets coefficients of quadratic equation
//!
//! @param [out] a First coefficient
//! @param [out] b Second coefficient
//! @param [out] c Third coefficient
//!
//! @return State_WORKING if input correct and State_EQUATION_FAILED if not
//--------------------------------------------------------------------------
enum State getCoefficients(Coefficients* user_input) {
    assert (isFinite(user_input->first_coefficient));
    assert (isFinite(user_input->second_coefficient));
    assert (isFinite(user_input->third_coefficient));

    clearScreen();
    printf("Для решения уравнения вида ax^2 + bx + c = 0 введите по порядку все коэффициенты a, b, c\n");

    printf("Введите первый коэффициент(a): ");
    if (scanf("%lf", &user_input->first_coefficient) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    printf("Введите второй коэффициент(b): ");
    if (scanf("%lf", &user_input->second_coefficient) != 1) {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    printf("Введите третий коэффициент(c): ");
    if (scanf("%lf", &user_input->third_coefficient) != 1) {
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
        case NumberOfRoots_ZERO_ROOTS:
            printf("Уравнение не имеет решений в действительных числах\n");
            return State_WORKING;

        case NumberOfRoots_ONE_ROOT:
            printf("Уравнение имеет один корень: %lf\n", first_root);
            return State_WORKING;

        case NumberOfRoots_TWO_ROOTS:
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
