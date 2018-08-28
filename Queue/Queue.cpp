// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "queue.h"

int main()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	init(queue, 100);
	int m, v, n;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &v);
		push(queue, v);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		if (!empty(queue))
		{
			pop(queue);
		}
	}
	if (!empty(queue))
	{
		printf("%d\n", front(queue));
	}
	output(queue);
	free(queue);

    return 0;
}

