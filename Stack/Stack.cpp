// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "expressionevaluation.h"
#include "rpn.h"

int main()
{
	/*Stack *numbers = (Stack *)malloc(sizeof(Stack));
	Stack *operators = (Stack *)malloc(sizeof(Stack));
	int m, n;
	scanf("%d", &m);
	init(numbers, m);
	init(operators, m);
	char *buffer = (char *)malloc(sizeof(char) * m);
	scanf("%s", buffer);
	int i = 0;
	while (i < m)
	{
		if (isdigit(buffer[i]))
		{
			push(numbers, buffer[i] - '0');
			i++;
		}
		else
		{
			if (empty(operators) || precede(buffer[i], top(operators)))
			{
				push(operators, buffer[i]);
				i++;
			}
			else
			{
				calc(numbers, operators);
			}
		}
	}
	while (!empty(operators))
	{
		calc(numbers, operators);
	}
	printf("%d\n", top(numbers));
	clear(numbers);
	clear(operators);
	free(buffer);*/

	Stack *numbers = (Stack *)malloc(sizeof(Stack));
	Stack *operators = (Stack *)malloc(sizeof(Stack));
	int m;
	scanf("%d", &m);
	init(numbers, m);
	init(operators, m);
	char *buffer = (char *)malloc(sizeof(char) * m);
	scanf("%s", buffer);
	output_rpn(buffer, numbers, operators);

	int i = 0;
	while (i <= numbers->top_index)
	{
		printf("%c", numbers->elements[i]);
		i++;
	}
	printf("\n");

	free(buffer);
	clear(numbers);
	clear(operators);

    return 0;
}

