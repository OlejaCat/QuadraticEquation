#include "command_processing.h"

#include <string.h>

#include "user_interaction.h"


CalledFlag proccess_flags(const int argc, const char **argv)
{
    if (!strcmp(argv[1], HELP_FLAG))
    {
        return CalledFlag_HELP;
    }
    else if (!strcmp(argv[1], TEST_FLAG) && RUN_TEST_IN_PROGRAM)
    {
        return CalledFlag_TEST;
    }
    else if (!strcmp(argv[1], VERSION_FLAG))
    {
        return CalledFlag_VERSION;
    }
    else if (!strcmp(argv[1], USER_FLAG))
    {
        return CalledFlag_USER;
    }
    else if (!strcmp(argv[1], FAST_SOLVE_FLAG))
    {
        return (argc == 5) ? CalledFlag_FAST_SOLVE : CalledFlag_FEW_ARGUMENTS;
    }
    else
    {
        return CalledFlag_NO_FLAG;
    }
}
