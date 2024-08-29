#ifndef HELPFUL_FUNCTIONS_H
#define HELPFUL_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>

#include "constants.h"

#ifndef NDEBUG
#define assertStrict(expression_string) \
 do \
    {assertStrict_(#expression_string, expression_string, __FILE__, __func__, __LINE__);} \
 while (0)
#else
#   define assertStrict(expesssion_string) ;
#endif

#ifndef NDEBUG
#define assertSoft(expression_string) \
 assertSoft_(#expression_string, expression_string, __FILE__, __func__, __LINE__)
#else
#define assertSoft(expesssion_string) (0)
#endif

#define SIZE_OF_ARRAY(arr) (sizeof(arr) / sizeof(arr[0]))

static const double EPS =  1e-8;


typedef enum ClearBufferMessage
{
    ClearBufferMessage_NOT_ONLY_SPACES = 0,
    ClearBufferMessage_ONLY_SPACES     = 1,
} ClearBufferMessage;

//--------------------------
//! Prints help message
//--------------------------
void printHelpMessage(void);

//------------------------------------------------------
//! Checks if number is negative or positive infinity
//!
//! @param [in] n double number
//!
//! @return True or False
//------------------------------------------------------
bool isInf(double n);

//-----------------------------
//! Checks if number is NaN
//!
//! @param [in] n double number
//!
//! @return True or False
//-----------------------------
bool isNan(double n);

//-----------------------------
//! Checks if number is finite
//!
//! @param [in] n double number
//!
//! @return True or False
//-----------------------------
bool isFinite(double n);

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if a is equal to b and False if a is not equal to b
//-----------------------------------------------------------------------
bool equatTwoDoubles (double a, double b);

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if a is greater than b and False if a is less than b
//-----------------------------------------------------------------------
bool compareGreaterTwoDoubles (double a, double b);

//-----------------------------------------------------------------------
//! Compares two numbers in double format
//!
//! @param [in] a First double number
//! @param [in] b Second double number
//!
//! @return True if b is greater than a and False if b is less than a
//-----------------------------------------------------------------------
bool compareLessTwoDoubles (double a, double b);

//----------------------------------------------
//! Swaps two numbers in double format
//!
//! @param [out] a     First variable
//! @param [out] b     Second variable
//! @param [in]  size  Size of type of variable
//!
//! @note Variables need to be in one type
//----------------------------------------------
void swap(void* a, void* b, size_t size);

//----------------
//! Cleans screen
//----------------
void clearScreen(void);

//----------------------------------------------------------------------------
//! Clears input buffer
//!
//! @return  if buffer wa only spaces returns ClearBufferMessage_ONLY_SPACES
//!          and ClearBufferMessage_NOT_ONLY_SPACES if not
//----------------------------------------------------------------------------
ClearBufferMessage clearBuffer(void);

//----------------------------------------------------------
//! Dublicates an assert functionality
//!
//! @param [in] expression_string  expression that is given
//! @param [in] expression         value of given expression
//! @param [in] file_name          file name where assert is
//! @param [in] line               line where is assert
//-----------------------------------------------------------
void assertStrict_(const char* expression_string,
                   bool        expression,
                   const char* file_name,
                   const char* function_name,
                   int         line);

//---------------------------------------------------------------
//! Dublicates an assert functionality but is just returns State
//!
//! @param [in] expression_string  expression that is given
//! @param [in] expression         value of given expression
//! @param [in] file_name          file name where assert is
//! @param [in] line               line where is assert
//!
//! @return State
//---------------------------------------------------------------
State assertSoft_(const char* expression_string,
                  bool        expression,
                  const char* file_name,
                  const char* function_name,
                  int         line);

#endif // HELPFUL_FUNCTIONS_H
