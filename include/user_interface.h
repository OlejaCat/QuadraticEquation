#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "constants.h"

static const char QUIT_COMMAND[] = "quit";
static const char SOLVE_COMMAND[] = "solve";
static const char Q_COMMAND[] = "q";
static const char S_COMMAND[] = "s";

enum State runUserInterface();

#endif // USER_INTERFACE_H
