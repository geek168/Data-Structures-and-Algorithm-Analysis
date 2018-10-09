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