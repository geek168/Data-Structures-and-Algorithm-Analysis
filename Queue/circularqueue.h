#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int *data;
	int head, tail, length, count;
} Queue;

void init_cq(Queue *q, int length);

void push_cq(Queue *q, int element);

void pop_cq(Queue *q);

int empty_cq(Queue *q);

int front_cq(Queue *q);

void output_cq(Queue *q);

void clear_cq(Queue *q);
