#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "../include/helpful_functions.h"
#include "../include/solve_quadratic.h"
#include "../include/constants.h"
#include "../include/unit_test.h"
#include "../include/user_interaction.h"
#include "../include/string_color.h"
#include "../include/user_interface.h"


int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("For help type %s %s\n", argv[0], HELP_FLAG);
        return State_NO_INPUT;
    }

    if (!strcmp(argv[1], HELP_FLAG)) {
        printf(HELP_MESSAGE);
    } else if (!strcmp(argv[1], TEST_FLAG)) {
        printf(BOLD_CYAN "Запускаем...\n");
        sleep(1);
        runTests();
    } else if (!strcmp(argv[1], VERSION_FLAG)) {
        printf(VERSION);
    } else if (!strcmp(argv[1], USER_FLAG)) {
        printf(BOLD_CYAN "Запускаем...\n");
        sleep(1); // hehe
        runUserInterface();
    } else if (!strcmp(argv[1], FAST_SOLVE_FLAG)) {
        Coefficients user_coefficients = {0, 0, 0};

        if (sscanf(argv[2], "%lf", &user_coefficients.first_coefficient) != 1
            || sscanf(argv[3], "%lf", &user_coefficients.second_coefficient) != 1
            || sscanf(argv[4], "%lf", &user_coefficients.third_coefficient) != 1)
        {
            printf(WRONG_INPUT_MESSAGE);
            return State_INPUT_FAILED;
        }

        double first_root = 0;
        double second_root = 0;
        NumberOfRoots number_of_roots = solveEquation(user_coefficients,
                                                      &first_root,
                                                      &second_root);

        printRoots(number_of_roots, first_root, second_root);
    } else {
        printf("Unknown parameter: '%s'. Type %s %s for help.\n", argv[1], argv[0], HELP_FLAG);
    }

    return State_WORKING;
}
