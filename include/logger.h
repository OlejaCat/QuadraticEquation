#ifndef LOGGER_H
#define LOGGER_H

#include "constants.h"

#define SIZE_OF_TIMESTAMP 10

#ifndef NDEBUG
#define writeLog(level, ...) writeLog_(level, __FILE__, __func__, __LINE__, __VA_ARGS__);
#else
#define writeLog(level, ...);
#endif

static const char PATH_LOG_FILE[]  = "logfile.txt";

typedef enum LogLevel {
    LogLevel_DEBUG    = 0,
    LogLevel_INFO     = 1,
    LogLevel_WARNING  = 2,
    LogLevel_ERROR    = 3,
    LogLevel_CRITICAL = 4,
} LogLevel;

//------------------------------------------------------------------
//! Write log into input file (look logger.h)
//!
//! @param [in] level    A level of logging
//! @param [in] file     Name of file where logging was called
//! @param [in] function Name of function where logging was called
//! @param [in] line     Line where logging was called
//! @param [in] message  Logging message
//!
//! @return State
//------------------------------------------------------------------
State writeLog_(LogLevel    level,
                const char* file,
                const char* function,
                int         line,
                const char* message,
                ...);

//---------------------------------------------------
//! Opens a log file
//!
//! @param [in] path_to_file path to logging file
//!
//! @return State
//---------------------------------------------------
State openLogFile(const char* path_to_file);

#endif // LOGGER_H
