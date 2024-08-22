#include <stdio.h>
#include <string.h>
#include "../include/helpful_functions.h"
#include "../include/solve_quadratic.h"
#include "../include/constants.h"
#include "../include/unit_test.h"
#include "../include/user_interaction.h"


int main() {
    runTests();

    printf("Чтобы выйти из программы введите `q`, чтобы решить квадратку введите `s`\n");
    char user_input[30] = {0};

    while (true) {
        printf("eq:");
        scanf("%s", &user_input);
        if (strcmp(user_input, "quit") == 0 || strcmp(user_input, "q") == 0) {
            break;
        } else if (strcmp(user_input, "solve") == 0 || strcmp(user_input, "s") == 0) {
            double first_coefficient = 0;
            double second_coefficient = 0;
            double third_coefficient = 0;

            enum State exit_code_input = getCoefficients(&first_coefficient, &second_coefficient, &third_coefficient);

            if (exit_code_input == State_INPUT_FAILED) {
                continue;
            }

            double first_root = 0;
            double second_root = 0;
            enum NumberOfRoots number_of_roots = solveEquation(first_coefficient,
                                         second_coefficient,
                                         third_coefficient,
                                         &first_root,
                                         &second_root);

            printRoots(number_of_roots, first_root, second_root);
        } else {
            printf("Неизвестная команда\n");
        }
    }
    return State_WORKING;
}
