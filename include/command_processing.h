#ifndef COMMAND_PROCESSING_H
#define COMMAND_PROCESSING_H

#ifndef NDEBUG
#define RUN_TEST_IN_PROGRAM 1
#else
#define RUN_TEST_IN_PROGRAM 0
#endif

typedef enum CalledFlag
{
    CalledFlag_HELP          = 0,
    CalledFlag_VERSION       = 1,
    CalledFlag_USER          = 2,
    CalledFlag_FAST_SOLVE    = 3,
    CalledFlag_NO_FLAG       = 4,
    CalledFlag_TEST          = 5,
    CalledFlag_FEW_ARGUMENTS = 6,
} CalledFlag;

//----------------------------------------
//! Parses terminal arguments
//!
//! @param [in] argc Number of arguments
//! @param [in] argv Arguments
//!
//! @return enum CalledFlag
//----------------------------------------
CalledFlag proccess_flags(const int argc, const char **argv);

#endif // COMMAND_PROCESSING_H
