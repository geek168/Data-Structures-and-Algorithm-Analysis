#include "queue.h"


void init(Queue *q, int length) 
{
	q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
}

void push(Queue *q, int element)
{
	if (q->tail + 1 >= q->length)
	{
		return;
	}
	q->tail++;
	q->data[q->tail] = element;
}

void pop(Queue *q)
{
	q->head++;
}

int empty(Queue *q)
{
	return q->head > q->tail;
}

int front(Queue *q)
{
	return q->data[q->head];
}

void output(Queue *q)
{
	int count = 0;
	for (int i = q->head; i <= q->tail; i++)
	{
		if (count > 0)
		{
			printf(" ");
		}
		printf("%d", q->data[i]);
		count++;
	}
	printf("\n");
}

void clear(Queue *q)
{
	free(q->data);
	free(q);
}