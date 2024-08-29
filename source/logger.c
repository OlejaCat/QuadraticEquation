#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "helpful_functions.h"


// static --------------------------------------------------------------------------------------------------------------


static FILE* logger_file = NULL;

//----------------------------------------
//! Converts level to string
//!
//! @param [in] level Level of logging
//!
//! @return A const char string
//----------------------------------------
static const char* levelToString(const LogLevel level);

//-----------------------------------------------
//! Closes file
//-----------------------------------------------
static void closeLogFile(void);


// global --------------------------------------------------------------------------------------------------------------


State openLogFile(const char* path_to_file)
{
    assertStrict(path_to_file != NULL);

    logger_file = fopen(path_to_file, "w");
    if (!logger_file)
    {
        return State_READ_FILE_ERROR;
    }

    int return_code_buf = setvbuf(logger_file, NULL, _IONBF, 0);
    if (!return_code_buf)
    {
        return State_READ_FILE_ERROR;
    }

    int return_code_exit = atexit(closeLogFile);
    if (!return_code_exit)
    {
        return State_CLOSE_FILE_ERROR;
    }

    return State_WORKING;
}


State writeLog_(LogLevel    level,
                const char* file,
                const char* function,
                int         line,
                const char* message,
                ...)
{
    assertStrict(message  != NULL);
    assertStrict(file     != NULL);
    assertStrict(function != NULL);

    if (!logger_file)
    {
        return State_READ_FILE_ERROR;
    }

    fprintf(logger_file, "%s: %s:%d In function: %s\nMessage: ",
                         levelToString(level),
                         file,
                         line,
                         function);

    va_list parametrs;
    va_start(parametrs, message);

    vfprintf(logger_file, message, parametrs);

    va_end(parametrs);

    return State_WORKING;
}


// static --------------------------------------------------------------------------------------------------------------


static void closeLogFile(void)
{
    fclose(logger_file);
    logger_file = NULL;
}


static const char* levelToString(const LogLevel level) {
    switch (level)
    {
        case LogLevel_DEBUG:
            return "DEBUG";

        case LogLevel_INFO:
            return "INFO";

        case LogLevel_WARNING:
            return "WARNING";

        case LogLevel_ERROR:
            return "ERROR";

        case LogLevel_CRITICAL:
            return "CRITICAL";

        default:
            return "UNKNOWN";
    }
}

