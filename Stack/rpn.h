#include <ctype.h>
#include "stack.h"

void output_rpn(char *buffer, Stack *numbers, Stack *operators);

int precede_rpn(int a, int b);