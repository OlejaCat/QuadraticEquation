#include "../include/user_interaction.h"

#include <stdio.h>
#include <assert.h>

#include "../include/solve_quadratic.h"
#include "../include/helpful_functions.h"
#include "../include/constants.h"


//--------------------------------------------------------------------------
//! Gets coefficients of quadratic equation
//!
//! @param [out] user_input
//!
//! @return State_WORKING if input correct and State_EQUATION_FAILED if not
//--------------------------------------------------------------------------
State getCoefficientsSlow(Coefficients* user_input)
{
    assert (isFinite(user_input->first_coefficient));
    assert (isFinite(user_input->second_coefficient));
    assert (isFinite(user_input->third_coefficient));

    clearScreen();
    printf("Для решения уравнения вида ax^2 + bx + c = 0 введите по порядку все коэффициенты a, b, c\n");

    printf("Введите первый коэффициент(a): ");
    if (scanf("%lf", &user_input->first_coefficient) != 1)
    {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    printf("Введите второй коэффициент(b): ");
    if (scanf("%lf", &user_input->second_coefficient) != 1)
    {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    printf("Введите третий коэффициент(c): ");
    if (scanf("%lf", &user_input->third_coefficient) != 1)
    {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    return State_WORKING;
}


// //--------------------------------------------------------------------------
// //! Gets coefficients of quadratic equation
// //!
// //! @param [out] user_input
// //!
// //! @return State_WORKING if input correct and State_EQUATION_FAILED if not
// //!
// //! @note The same as `slow` version but makes it one line and with argv
// //--------------------------------------------------------------------------
State fastSolve(char** argv)
{
    Coefficients user_coefficients = {0, 0, 0};

    if (   sscanf(argv[2], "%lf", &user_coefficients.first_coefficient)  != 1
        || sscanf(argv[3], "%lf", &user_coefficients.second_coefficient) != 1
        || sscanf(argv[4], "%lf", &user_coefficients.third_coefficient)  != 1)
    {
        printf(WRONG_INPUT_MESSAGE);
        return State_INPUT_FAILED;
    }

    double first_root = 0;
    double second_root = 0;
    NumberOfRoots number_of_roots = solveEquation(user_coefficients,
                                                    &first_root,
                                                    &second_root);

    printRoots(number_of_roots, first_root, second_root);

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
State printRoots(int number_of_roots, double first_root, double second_root)
{
    assert (isFinite(number_of_roots));
    assert (isFinite(first_root));
    assert (isFinite(second_root));

    switch (number_of_roots) {
        case NumberOfRoots_ZERO_ROOTS:
            printf("Уравнение не имеет решений в действительных числах\n");
            return State_WORKING;

        case NumberOfRoots_ONE_ROOT:
            printf("Уравнение имеет один корень: %g\n", first_root);
            return State_WORKING;

        case NumberOfRoots_TWO_ROOTS:
            printf("Уравнение имеет два решения: %g, %g\n", first_root, second_root);
            return State_WORKING;

        case NumberOfRoots_INFINITE_ROOTS:
            printf("Уравнение имеет бесконечное множество корней\n");
            return State_WORKING;

        default:
            printf("Что-то пошло не так...\n");
            return State_EQUATION_FAILED;

    }
}
