#include "expressionevaluation.h"

int precede(int a, int b)
{
	if (a == '*' && (b == '+' || b == '-'))
	{
		return 1;
	}
	else if (a == '/' && (b == '+' || b == '-'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int operate(char theta, int a, int b)
{
	if (theta == '+')
	{
		return a + b;
	}
	else if (theta == '-')
	{
		return b - a;
	}
	else if (theta == '*')
	{
		return a*b;
	}
	else if (theta == '/')
	{
		return b / a;
	}
}

void calc(Stack *numbers, Stack *operators)
{
	int a = top(numbers);
	pop(numbers);
	int b = top(numbers);
	pop(numbers);
	int c = top(operators);
	pop(operators);
	push(numbers, operate(c, a, b));
}
