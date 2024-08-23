#include "../include/user_interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/solve_quadratic.h"
#include "../include/user_interaction.h"
#include "../include/string_color.h"
#include "../include/helpful_functions.h"


State runUserInterface()
{
    clearScreen();

    printf(BOLD_GREEN "Чтобы выйти из программы введите `%s` или `%s`"
           ",чтобы решить квадратку введите `%s` или `%s`\n" RESET,
           QUIT_COMMAND, Q_COMMAND, SOLVE_COMMAND, S_COMMAND);

    char user_input[30] = {0};

    while (true)
    {
        printf("eq:");
        scanf("%s", &user_input);
        if (strcmp(user_input, QUIT_COMMAND) == 0 || strcmp(user_input, Q_COMMAND) == 0)
        {
            break;
        }
        else if (strcmp(user_input, SOLVE_COMMAND) == 0
              || strcmp(user_input, S_COMMAND)     == 0)
        {
            Coefficients user_coefficients = {0, 0, 0};

            State exit_code_input = getCoefficientsSlow(&user_coefficients);

            if (exit_code_input == State_INPUT_FAILED)
            {
                continue;
            }

            double first_root = 0;
            double second_root = 0;

            NumberOfRoots number_of_roots = solveEquation(user_coefficients,
                                                          &first_root,
                                                          &second_root);

            printRoots(number_of_roots, first_root, second_root);
        }
        else
        {
            printf("Неизвестная команда\n");
        }
    }

    return State_WORKING;
}
