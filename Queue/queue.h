#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int *data;
	int head, tail, length;
} Queue;

void init(Queue *q, int length);

void push(Queue *q, int element);

void pop(Queue *q);

int empty(Queue *q);

int front(Queue *q);

void output(Queue *q);

void clear(Queue *q);