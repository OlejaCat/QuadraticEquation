#include "user_interaction.h"

#include <stdio.h>
#include <assert.h>

#include "solve_quadratic.h"
#include "helpful_functions.h"
#include "constants.h"


// static --------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//! Makes output of roots
//!
//! @param [in] number_of_roots  number of roots
//! @param [in]      first_root  first root
//! @param [in]     second_root  second root
//!
//! @return State_WORKING if everething OK and State_EQUATION_FAILED if not OK
//-------------------------------------------------------------------------------
static State printRoots(int number_of_roots, double first_root, double second_root);

//-----------------------------------------------------------------
//! Gets one coefficient also if input is incorrect asks again
//!
//! @param [in]  name_of_coefficient         name of coefficient
//! @param [in]  short_name_of_coefficient   short name (like `a`)
//! @param [out] coefficient                 pointer to coefficient
//!
//! @return State_EXIT_WITH_EOF if exit with EOF
//!         and State_WORKING if everything good
//-----------------------------------------------------------------
static State getOneCoefficient(const char* name_of_coefficient,
                               const char* short_name_of_coefficient,
                               double* coefficient);

//--------------------------------------------------------------------------
//! Gets coefficients of quadratic equation
//!
//! @param [out] user_input  input of user coefficients
//!
//! @return State_WORKING if input correct and State_EQUATION_FAILED if not
//--------------------------------------------------------------------------
static State getCoefficientsSlow(Coefficients* user_input);


// global --------------------------------------------------------------------------------------------------------------


void emptyInputMessage(const char* input_parameter,
                       const char* solver)
{
    printf("Unknown parameter: '%s'. Type %s %s for help.\n",
           input_parameter,
           solver,
           HELP_FLAG);
}

State scanCoefficientsAndPrintAnswer(void) {
    Coefficients user_coefficients = {0, 0, 0};

    State exit_code_input = getCoefficientsSlow(&user_coefficients);

    if (exit_code_input == State_INPUT_FAILED)
    {
        clearScreen();
        return State_INPUT_FAILED;
    }

    double first_root  = 0;
    double second_root = 0;

    NumberOfRoots number_of_roots = solveEquation(user_coefficients,
                                                  &first_root,
                                                  &second_root);

    printRoots(number_of_roots, first_root, second_root);

    return State_WORKING;
}


State fastSolve(const char** argv)
{
    assertStrict(argv != NULL);

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


// static --------------------------------------------------------------------------------------------------------------


static State printRoots(const int number_of_roots,
                 const double first_root,
                 const double second_root)
{
    assertStrict(isFinite(number_of_roots));
    assertStrict(isFinite(first_root));
    assertStrict(isFinite(second_root));

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


static State getOneCoefficient(const char* name_of_coefficient,
                               const char* short_name_of_coefficient,
                               double* coefficient)
{
    assertStrict(name_of_coefficient       != NULL);
    assertStrict(short_name_of_coefficient != NULL);
    assertStrict(coefficient               != NULL);

    while (true)
    {
        printf("Введите %s коэффициент(%s): ",
               name_of_coefficient,
               short_name_of_coefficient);

        int result_of_scanf = scanf("%lf", coefficient);

        if (result_of_scanf == EOF)
        {
            clearBuffer();
            clearerr(stdin);
            return State_EXIT_WITH_EOF;
        }

        int user_char = 0;
        if ((user_char = getchar()) != (int) '\n')
        {
            printf(WRONG_INPUT_MESSAGE);
            clearBuffer();
            continue;
        }

        return State_WORKING;
    }
}


static State getCoefficientsSlow(Coefficients* user_input)
{
    assertStrict(user_input != NULL);

    assertStrict(isFinite(user_input->first_coefficient));
    assertStrict(isFinite(user_input->second_coefficient));
    assertStrict(isFinite(user_input->third_coefficient));

    clearScreen();
    printf("Для решения уравнения вида ax^2 + bx + c = 0 введите по порядку все коэффициенты a, b, c\n");

    if (getOneCoefficient("первый", "a", &user_input->first_coefficient) == State_EXIT_WITH_EOF)
    {
        return State_INPUT_FAILED;
    }

    if (getOneCoefficient("второй", "b", &user_input->second_coefficient) == State_EXIT_WITH_EOF)
    {
        return State_INPUT_FAILED;
    }

    if (getOneCoefficient("третий", "c", &user_input->third_coefficient) == State_EXIT_WITH_EOF)
    {
        return State_INPUT_FAILED;
    }

    return State_WORKING;
}
