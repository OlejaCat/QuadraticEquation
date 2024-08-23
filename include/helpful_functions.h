#ifndef HELPFUL_FUNCTIONS_H
#define HELPFUL_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>

#include "constants.h"

#ifndef NDEBUG
#   define assertStrict(expression_string) \
    _assertStrict(#expression_string, expression_string, __FILE__, __func__, __LINE__)
#else
#   define assertStrict(expesssion_string);
#endif

#ifndef NDEBUG
#   define assertSoft(expression_string) \
    _assertSoft(#expression_string, expression_string, __FILE__, __func__, __LINE__)
#else
#   define assertSoft(expesssion_string);
#endif

bool isInf(double n);
bool isNan(double n);
bool isFinite(double n);
bool equatTwoDoubles (double a, double b);
bool compareGreaterTwoDoubles (double a, double b);
bool compareLesserTwoDoubles (double a, double b);
void swap(void* a, void* b, size_t size);
void clearScreen();
void _assertStrict(const char* expression_string,
                   bool        expression,
                   const char* file_name,
                   const char* function_name,
                   int         line);
State _assertSoft(const char* expression_string,
                     bool        expression,
                     const char* file_name,
                     const char* function_name,
                     int         line);

#endif // HELPFUL_FUNCTIONS_H
