#ifndef USER_INTERACTION
#define USER_INTERACTION

#include "constants.h"
#include "solve_quadratic.h"

static const char   TEST_FLAG[]             =  "--test";
static const char   VERSION_FLAG[]          =  "--version";
static const char   USER_FLAG[]             =  "--user";
static const char   HELP_FLAG[]             =  "--help";
static const char   FAST_SOLVE_FLAG[]       =  "--fast-solve";

//--------------------------------------------------------------------------
//! Gets coefficients of quadratic equation
//!
//! @param [out] user_input  input of user coefficients
//!
//! @return State_WORKING if input correct and State_EQUATION_FAILED if not
//--------------------------------------------------------------------------
State getCoefficientsSlow(Coefficients* user_input);

//-------------------------------------------------------------------------------
//! Makes output of roots
//!
//! @param [in] number_of_roots  number of roots
//! @param [in]      first_root  first root
//! @param [in]     second_root  second root
//!
//! @return State_WORKING if everething OK and State_EQUATION_FAILED if not OK
//-------------------------------------------------------------------------------
State printRoots(int number_of_roots, double first_root, double second_root);

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

//-----------------------------------------------------------------
//! Gets one coefficient also if input is incorrect asks again
//!
//! @param [in]  name_of_coefficient         name of coefficient
//! @param [in]  short_name_of_coefficient   short name (like `a`)
//! @param [out] coefficient                 pointer to coefficient
//!
//! @return State_EXIT_WITH_EOF if exit with EOF
//!         and State_WORKING if everything good
//-----------------------------------------------------------------
State getOneCoefficient(const char* name_of_coefficient,
                        const char* short_name_of_coefficient,
                        double* coefficient);


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
