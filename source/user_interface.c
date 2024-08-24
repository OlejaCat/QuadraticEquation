#include "user_interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "solve_quadratic.h"
#include "user_interaction.h"
#include "string_color.h"
#include "helpful_functions.h"


State runUserInterface(void)
{
    clearScreen();

    printf(BOLD_GREEN "Чтобы выйти из программы введите `%s` или `%s`"
           ",чтобы решить квадратку введите `%s` или `%s`\n" RESET,
           QUIT_COMMAND, Q_COMMAND, SOLVE_COMMAND, S_COMMAND);

    // TODO const
    char user_input[SIZE_OF_BUFFER];

    while (true)
    {
        printf("eq:");
        int result_of_scanf = scanf("%9s", user_input);

        assertStrict (SIZE_OF_BUFFER - 1 == 9);

        ClearBufferMessage clear_buffer_message = clearBuffer();

        bool expression_quit = ( (clear_buffer_message == ClearBufferMessage_ONLY_SPACES)
                                  && (!strcmp(user_input, QUIT_COMMAND)
                                  || !strcmp(user_input, Q_COMMAND))
                               )
                               ||  result_of_scanf == EOF;

        if (expression_quit)
        {
            clearScreen();
            break;
        }
        else if (  clear_buffer_message == ClearBufferMessage_ONLY_SPACES
               && (!strcmp(user_input, SOLVE_COMMAND) ||  !strcmp(user_input, S_COMMAND)))
        {
            Coefficients user_coefficients = {0, 0, 0};

            State exit_code_input = getCoefficientsSlow(&user_coefficients);

            if (exit_code_input == State_INPUT_FAILED)
            {
                clearScreen();
                continue;
            }

            double first_root = 0;
            double second_root = 0;

            NumberOfRoots number_of_roots = solveEquation(user_coefficients,
                                                          &first_root,
                                                          &second_root);

            printRoots(number_of_roots, first_root, second_root);
        } else if (!strcmp(user_input, "clear") && clear_buffer_message == ClearBufferMessage_ONLY_SPACES)
        {
            clearScreen();
        }
        else
        {
            printf("Неизвестная команда\n");
        }
    }

    return State_WORKING;
}
