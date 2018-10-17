#include "linkedlist.h"

LinkedList insert_node(LinkedList head, int value)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->next = head;
	head = node;
	return head;
}

void init_graph(Graph_LinkedList *g, int n)
{
	g->n = n;
	for (int i = 0; i < n; i++)
	{
		g->edges[i] = NULL;
	}
	memset(g->visited, 0, sizeof(g->visited));
}

void init_queue(Queue *q, int size)
{
	q->size = size;
	q->data = (int *)malloc(sizeof(int) * size);
	q->head = 0;
	q->tail = -1;
}

void insert_graph(Graph_LinkedList *g, int a, int x, int y)
{
	if (x < 0 || x >= g->n || y < 0 || y >= g->n)
	{
		return;
	}

	if (a == 0) //有向图
	{
		g->edges[x] = insert_node(g->edges[x], y);
	}
	else if (a == 1) //无向图
	{
		g->edges[x] = insert_node(g->edges[x], y);
		g->edges[y] = insert_node(g->edges[y], x);
	}
}

void output_graph(Graph_LinkedList *g)
{
	for (int i = 0; i < g->n; i++)
	{
		printf("%d:", i);
		Node *h = g->edges[i];
		while (h != NULL)
		{
			printf(" %d", h->data);
			h = h->next;
		}
		printf("\n");
	}
}

void clear_graph(Graph_LinkedList *g)
{
	for (int i = 0; i < g->n; i++)
	{
		Node *h = g->edges[i];
		while (h != NULL)
		{
			Node *d = h;
			h = h->next;
			free(d);
		}
	}
	free(g);
}

void clear_queue(Queue *q)
{
	free(q->data);
	free(q);
}

void push(Queue *q, int data)
{
	if (q->tail + 1 >= q->size)
	{
		return;
	}
	q->tail++;
	q->data[q->tail] = data;
}

void pop(Queue *q)
{
	q->head++;
}

int empty_queue(Queue *q)
{
	if (q->head > q->tail) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int front(Queue *q)
{
	return q->data[q->head];
}

void dfs(Graph_LinkedList *g, int vertex)
{
	printf("%d\n", vertex);
	g->visited[vertex] = 1;

	for (Node *adj = g->edges[vertex]; adj != NULL; adj = adj->next)
	{
		if (!g->visited[adj->data])
		{
			dfs(g, adj->data);
		}
	}
}

void bfs(Graph_LinkedList *g, int vertex)
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	init_queue(q, g->n);
	push(q, vertex);
	g->visited[vertex] = 1;

	while (!empty_queue(q))
	{
		int index = front(q);
		printf("%d\n", index);
		pop(q);

		for (Node *adj = g->edges[index]; adj != NULL; adj = adj->next)
		{
			if (!g->visited[adj->data])
			{
				g->visited[adj->data] = 1;
				push(q, adj->data);
			}
		}
	}

	clear_queue(q);
}