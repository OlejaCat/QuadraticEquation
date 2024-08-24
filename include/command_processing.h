#ifndef COMMAND_PROCESSING_H
#define COMMAND_PROCESSING_H

typedef enum CalledFlag
{
    CalledFlag_help       = 0,
    CalledFlag_version    = 1,
    CalledFlag_user       = 2,
    CalledFlag_fast_solve = 3,
    CalledFlag_no_flag    = 4,
    CalledFlag_test       = 5,
} CalledFlag;

CalledFlag proccess_flags(const int argc, const char **argv);

#endif
