#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../include/helpful_functions.h"
#include "../include/constants.h"
#include "../include/unit_test.h"
#include "../include/user_interaction.h"
#include "../include/string_color.h"
#include "../include/user_interface.h"


int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        printf("For help type %s %s\n", argv[0], HELP_FLAG);
        return State_NO_INPUT;
    }

    if (!strcmp(argv[1], HELP_FLAG))
    {
        printf(HELP_MESSAGE);
    }
    else if (!strcmp(argv[1], TEST_FLAG))
    {
        printf(BOLD_CYAN "Запускаем...\n");
        sleep(1);
        runTests();
    }
    else if (!strcmp(argv[1], VERSION_FLAG))
    {
        printf(VERSION);
    }
    else if (!strcmp(argv[1], USER_FLAG))
    {
        printf(BOLD_CYAN "Запускаем...\n");
        sleep(1); // hehe
        runUserInterface();
    }
    else if (!strcmp(argv[1], FAST_SOLVE_FLAG)
          || argc != 4)
    {
        fastSolve(argv);
    }
    else
    {
        printf("Unknown parameter: '%s'. Type %s %s for help.\n", argv[1], argv[0], HELP_FLAG);
    }

    return State_WORKING;
}
