#include "user_interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "user_interaction.h"
#include "string_color.h"
#include "helpful_functions.h"


State runUserInterface(void)
{
    clearScreen();

    printf(BOLD_GREEN "Чтобы выйти из программы введите `%s` или `%s`"
           ",чтобы решить квадратку введите `%s` или `%s`\n" RESET,
           QUIT_COMMAND, Q_COMMAND, SOLVE_COMMAND, S_COMMAND);

    char user_input[SIZE_OF_BUFFER] = {0};

    while (true)
    {
        printf("eq:");
        int result_of_scanf = scanf("%79s", user_input);
        assertStrict(SIZE_OF_BUFFER - 1 == 79);

        ClearBufferMessage clear_buffer_message = clearBuffer();

        bool entered_quit_command = (clear_buffer_message == ClearBufferMessage_ONLY_SPACES)
                                    && (!strcmp(user_input, QUIT_COMMAND)
                                    || !strcmp(user_input, Q_COMMAND));

        bool expression_quit = entered_quit_command ||  result_of_scanf == EOF;

        if (expression_quit)
        {
            clearScreen();
            break;
        }
        else if (clear_buffer_message == ClearBufferMessage_ONLY_SPACES
                 && (!strcmp(user_input, SOLVE_COMMAND) || !strcmp(user_input, S_COMMAND)))
        {
            State exit_code_input = scanCoefficientsAndPrintAnswer();

            if (exit_code_input == State_INPUT_FAILED)
            {
                continue;
            }
        }
        else if (!strcmp(user_input, CLEAR) && clear_buffer_message == ClearBufferMessage_ONLY_SPACES)
        {
            clearScreen();
        }
        else
        {
            printf(UNKNOWN_COMMAND);
        }
    }

    return State_WORKING;
}
