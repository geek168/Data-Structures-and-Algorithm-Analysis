#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Stack
{
	int *elements;
	int max_size, top_index;
}Stack;

void init(Stack *stack, int input_size);

int push(Stack *stack, int element);

int pop(Stack *stack);

int top(Stack *stack);

int empty(Stack *stack);

void clear(Stack *stack);