#include "circularqueue.h"


void init_cq(Queue *q, int length)
{
	q->data = (int *)malloc(sizeof(int) * length);
	q->length = length;
	q->head = 0;
	q->tail = -1;
	q->count = 0;
}

void push_cq(Queue *q, int element)
{
	if (q->count >= q->length)
	{
		return;
	}
	q->tail = (q->tail + 1) % q->length;
	q->data[q->tail] = element;
	q->count++;
}

void pop_cq(Queue *q)
{
	q->head = (q->head + 1) % q->length;
	q->count--;
}

int empty_cq(Queue *q)
{
	return q->count == 0;
}

int front_cq(Queue *q)
{
	return q->data[q->head];
}

void output_cq(Queue *q)
{
	int i = q->head;
	int count = 0;
	do
	{
		if (count > 0)
		{
			printf(" ");
		}
		printf("%d", q->data[i]);
		i = (i + 1) % q->length;
		count++;
	} while (i != (q->tail + 1) % q->length);
	printf("\n");
}

void clear_cq(Queue *q)
{
	free(q->data);
	free(q);
}
