#ifndef HELPFUL_FUNCTIONS_H
#define HELPFUL_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>

bool isInf(double n);
bool isNan(double n);
bool isFinite(double n);
bool equatTwoDoubles (double a, double b);
bool compareGreaterTwoDoubles (double a, double b);
bool compareLesserTwoDoubles (double a, double b);
void swap(void* a, void* b, size_t size);
void clearScreen();

#endif // HELPFUL_FUNCTIONS_H
