#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "unit_test.h"
#include "user_interaction.h"
#include "user_interface.h"
#include "config.h"


int main(const int argc, const char** argv)
{
    // if no flags
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
        runTests();
    }
    else if (!strcmp(argv[1], VERSION_FLAG))
    {
        printf(VERSION);
    }
    else if (!strcmp(argv[1], USER_FLAG))
    {
        runUserInterface();
    }
    else if (!strcmp(argv[1], FAST_SOLVE_FLAG) && argc == 5)
    {
        fastSolve(argv);
    }
    else
    {
        printf("Unknown parameter: '%s'. Type %s %s for help.\n", argv[1], argv[0], HELP_FLAG);
    }

    return State_WORKING;
}
