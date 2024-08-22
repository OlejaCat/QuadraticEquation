#ifndef CONSTANTS_H
#define CONSTANTS_H


static const double EPS = 0.0000001;
static const char CLEAR_SCREEN[] = "\e[1;1H\e[2J";
static const char WRONG_INPUT_MESSAGE[] = "Некорректный ввод. Попробуйте снова\n";
static const char SOMETHING_WENT_WRONG[] = "Что-то пошло не так\n";

typedef struct coefficients {
    double first_coefficient;
    double second_coefficient;
    double third_coefficient;
} Coefficients;


enum State {
    State_WORKING         = 0,
    State_EQUATION_FAILED = 1,
    State_INPUT_FAILED    = 2,
    State_TEST_FAIL       = 3,
};

#endif // CONSTANTS_H
