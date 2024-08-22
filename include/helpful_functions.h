#ifndef HELPFUL_FUNCTIONS_H
#define HELPFUL_FUNCTIONS_H

#include <stdbool.h>

void swap(double* a, double* b);
bool isInf(double n);
bool isNan(double n);
bool isFinite(double n);
bool equatTwoDoubles (double a, double b);
bool compareGreaterTwoDoubles (double a, double b);
bool compareLesserTwoDoubles (double a, double b);
void clearScreen();

#endif // HELPFUL_FUNCTIONS_H
