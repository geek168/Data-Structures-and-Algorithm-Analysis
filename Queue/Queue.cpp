// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "queue.h"
#include "circularqueue.h"

int main()
{
	//Queue *queue = (Queue *)malloc(sizeof(Queue));
	//init(queue, 100);
	//int m, v, n;
	//scanf("%d", &m);
	//for (int i = 0; i < m; i++)
	//{
	//	scanf("%d", &v);
	//	push(queue, v);
	//}
	//scanf("%d", &n);
	//for (int i = 0; i < n; i++)
	//{
	//	if (!empty(queue))
	//	{
	//		pop(queue);
	//	}
	//}
	//if (!empty(queue))
	//{
	//	printf("%d\n", front(queue));
	//}
	//output(queue);
	//clear(queue);

	Queue *q = (Queue *)malloc(sizeof(Queue));
	init_cq(q, 100);
	for (int i = 1; i <= 10; i++) {
		push_cq(q, i);
	}
	output_cq(q);
	if (!empty_cq(q)) {
		printf("%d\n", front_cq(q));
		pop_cq(q);
	}
	output_cq(q);
	clear_cq(q);

    return 0;
}

