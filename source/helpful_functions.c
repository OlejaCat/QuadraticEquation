#include "helpful_functions.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

#include "constants.h"
#include "string_color.h"



ClearBufferMessage clearBuffer(void)
{
    int current_char = 0;
    bool only_spaces = true;
    while ((current_char = getchar()) != (int)'\n' && current_char != EOF)
    {
        if (!isspace((char)current_char))
        {
            only_spaces = false;
        }
    }

    return (only_spaces)
                ? ClearBufferMessage_ONLY_SPACES
                : ClearBufferMessage_NOT_ONLY_SPACES;
}


void assertStrict_(const char* expression_string,
                   const bool  expression,
                   const char* file_name,
                   const char* function_name,
                   const int   line)
{
    if (expression) { return ; }

    fprintf(stderr,
            BOLD_RED "Assert failed:\t%s\nSource:\t\t%s:%d\nIn function:\t%s\n" RESET,
            expression_string,
            file_name,
            line,
            function_name);
    abort();
}


State assertSoft_(const char* expression_string,
                  const bool  expression,
                  const char* file_name,
                  const char* function_name,
                  const int   line)
{
    if (!expression)
    {
        printf(BOLD_RED "Assert failed:\t%s\nSource:\t\t%s:%d\nIn function:\t%s\n" RESET,
               expression_string,
               file_name,
               line,
               function_name);
        return State_ASSERTION;
    }

    return State_WORKING;
}


void clearScreen(void)
{
    system("clear");
}


bool equatTwoDoubles (const double a, const double b)
{
    return (fabs(a - b) < EPS);
}


bool compareGreaterTwoDoubles (const double a, const double b)
{
    return (a - b > EPS);
}


bool compareLessTwoDoubles (const double a, const double b)
{
    return (b - a > EPS);
}


void swap(void* a, void* b, size_t size)
{
    assertStrict (a    != NULL);
    assertStrict (b    != NULL);

    char temp = 0;
    uint8_t* ua = (uint8_t*)a;
    uint8_t* ub = (uint8_t*)b;
    for (size_t i = 0; i < size; i++)
    {
        memcpy(&temp, ua + i, sizeof(uint8_t));
               memcpy(ua + i, ub + i, sizeof(uint8_t));
                       memcpy(ub + i, &temp, sizeof(uint8_t));
    }

    // TODO vectorised swap
}


bool isInf(const double n)
{
    return isNan(n * 0.0);
}


bool isNan(const double n)
{
    return n != n;
}


bool isFinite(const double n)
{
    return !isInf(n) && !isNan(n);
}
