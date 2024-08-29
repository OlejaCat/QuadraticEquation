#ifndef USER_INTERACTION
#define USER_INTERACTION

#include "constants.h"

static const char   CLEAR[]            =  "clear";
static const char   TEST_FLAG[]        =  "--test";
static const char   USER_FLAG[]        =  "--user";
static const char   HELP_FLAG[]        =  "--help";
static const char   VERSION_FLAG[]     =  "--version";
static const char   FAST_SOLVE_FLAG[]  =  "--fast-solve";

//----------------------------------------------
//! Get coefficeints of equation and print roots
//-----------------------------------------------
State scanCoefficientsAndPrintAnswer(void);

//--------------------------------------------------------------------------
//! Gets coefficients of quadratic equation
//!
//! @param [out] argv Arguments of command line
//!
//! @return State_WORKING if input correct and State_EQUATION_FAILED if not
//!
//! @note The same as `slow` version but makes it one line and with argv
//--------------------------------------------------------------------------
State fastSolve(const char** argv);

//-----------------------------------------------------
//! Prints that flag input is empty or no sush flag
//!
//! @param [in] input_parameter  flag that was inputed
//! @param [in] solver           solver idk
//!
//-----------------------------------------------------
void emptyInputMessage(const char* input_parameter,
                       const char* solver);

#endif // USER_INTERACTION
