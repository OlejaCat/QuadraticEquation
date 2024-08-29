#include <stdio.h>

#include "constants.h"
#include "user_interaction.h"
#include "command_processing.h"
#include "unit_test.h"
#include "user_interface.h"
#include "config.h"
#include "helpful_functions.h"
#include "logger.h"


int main(const int argc, const char** argv)
{
    // if no flags
    if (argc <= 1)
    {
        printf("For help type %s %s\n", argv[0], HELP_FLAG);
        return State_NO_INPUT;
    }

    openLogFile(PATH_LOG_FILE);
    writeLog(LogLevel_DEBUG, "Program started\n");

    CalledFlag flag = proccess_flags(argc, argv);

    switch (flag)
    {
        case CalledFlag_HELP:
            printHelpMessage();
            break;

        case CalledFlag_TEST:
            runTestsFromFile();
            break;

        case CalledFlag_USER:
            runUserInterface();
            break;

        case CalledFlag_VERSION:
            printf(VERSION);
            break;

        case CalledFlag_FAST_SOLVE:
            fastSolve(argv);
            break;

        case CalledFlag_NO_FLAG:
            emptyInputMessage(argv[1], argv[0]);
            break;

        case CalledFlag_FEW_ARGUMENTS:
            printf(FEW_ARGUMENTS);
            break;

        default:
            assertStrict(0 && "unexpected flag");
            break;
    }

    return State_WORKING;
}
