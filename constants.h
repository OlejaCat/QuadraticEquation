#ifndef CONSTANTS_H
#define CONSTANTS_H


const double EPS = 0.0000001;
const char CLEAR_SCREEN[] = "\e[1;1H\e[2J";
const char WRONG_INPUT_MESSAGE[] = "Некорректный ввод. Попробуйте снова\n";
const char SOMETHING_WENT_WRONG[] = "Что-то пошло не так\n";

enum State {
    State_WORKING         = 0,
    State_EQUATION_FAILED = 1,
    State_INPUT_FAILED    = 2,
    State_TEST_FAIL       = 3,
};

#endif // CONSTANTS_H
