#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "string_color.h"

// macros to count array size
#define SIZE_OF_ARRAY(arr) (sizeof(arr) / sizeof(arr[0]))

// text constansts
static const char   TEST_FLAG[]             =  "--test";
static const char   VERSION_FLAG[]          =  "--version";
static const char   USER_FLAG[]             =  "--user";
static const char   HELP_FLAG[]             =  "--help";
static const char   FAST_SOLVE_FLAG[]       =  "--fast-solve";
static const char   CLEAR_SCREEN[]          =  "\e[1;1H\e[2J";
static const char   WRONG_INPUT_MESSAGE[]   =  BOLD_YELLOW "Некорректный ввод. Попробуйте снова\n";
static const char   SOMETHING_WENT_WRONG[]  =  BOLD_RED "Что-то пошло не так\n";
static const double EPS                     =  0.000000001;

static const char HELP_MESSAGE[] = (
    "Аргументы:\n"
    "   --help\t\t\tвыводит слова поддержки\n"
    "   --version\t\t\tвыводит версию\n"
    "   --test\t\t\tпечатает тесты\n"
    "   --user\t\t\tзапускает пользовательский интерфейс\n"
    "   --fast-solve [a] [b] [c]\tвведите в строку коэффициенты уравнения вида ax^2 + bx + c = 0\n"
);

static const char VERSION[] = "Версия 1\n";

// structures
typedef struct Coefficients
{
    double first_coefficient;
    double second_coefficient;
    double third_coefficient;
} Coefficients;

typedef enum State
{
    State_WORKING          =  0,
    State_EQUATION_FAILED  =  1,
    State_INPUT_FAILED     =  2,
    State_TEST_FAIL        =  3,
    State_NO_INPUT         =  4,
    State_ASSERTION        =  5,
} State;

#endif // CONSTANTS_H
