#include "command_processing.h"

#include <string.h>
#include <stdio.h>

#include "user_interaction.h"
#include "user_interface.h"
#include "config.h"


CalledFlag proccess_flags(const int argc, const char **argv) {
    if (!strcmp(argv[1], HELP_FLAG))
    {
        return CalledFlag_help;
    }
    else if (!strcmp(argv[1], TEST_FLAG))
    {
        return CalledFlag_test;
    }
    else if (!strcmp(argv[1], VERSION_FLAG))
    {
        return CalledFlag_version;
    }
    else if (!strcmp(argv[1], USER_FLAG))
    {
        return CalledFlag_user;
    }
    else if (!strcmp(argv[1], FAST_SOLVE_FLAG))
    {
        return (argc == 5) ? CalledFlag_fast_solve : CalledFlag_few_arguments;
    }
    else
    {
        return CalledFlag_no_flag;
    }
}
