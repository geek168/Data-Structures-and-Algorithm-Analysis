#include "stack.h"


void init(Stack *stack, int input_size)
{
	stack->elements = (int *)malloc(sizeof(int) * input_size);
	stack->max_size = input_size;
	stack->top_index = -1;
}

int push(Stack *stack, int element)
{
	if (stack->top_index >= stack->max_size - 1)
	{
		return ERROR;
	}
	stack->top_index++;
	stack->elements[stack->top_index] = element;
	return OK;
}

int pop(Stack *stack)
{
	if (empty(stack))
	{
		return ERROR;
	}
	else
	{
		stack->top_index--;
		return OK;
	}
}

int top(Stack *stack)
{
	return stack->elements[stack->top_index];
}

int empty(Stack *stack)
{
	return stack->top_index < 0;
}

void clear(Stack *stack)
{
	free(stack->elements);
	free(stack);
}