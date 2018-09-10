#include "rpn.h"

int precede_rpn(int a, int b)
{
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void output_rpn(char *buffer, Stack *numbers, Stack *operators)
{
	int len = _mbstrlen(buffer);
	int i = 0;
	while (i < len)
	{
		if (isdigit(buffer[i]))
		{
			push(numbers, buffer[i]);
		}
		else
		{
			if (empty(operators) || buffer[i] == '(' || top(operators) == '(')
			{
				push(operators, buffer[i]);
			}
			else
			{
				if (buffer[i] == ')')
				{
					int t = top(operators);
					while (t != '(')
					{
						push(numbers, t);
						pop(operators);
						t = top(operators);
					}
					if (t == '(')
					{
						pop(operators);
					}
				}
				else
				{
					if (precede_rpn(buffer[i], top(operators)))
					{
						push(numbers, buffer[i + 1]);
						push(numbers, buffer[i]);
						i++;
					}
					else
					{
						push(numbers, top(operators));
						pop(operators);
						push(operators, buffer[i]);
					}
				}
			}
		}

		i++;
	}

	while (!empty(operators))
	{
		push(numbers, top(operators));
		pop(operators);
	}
}