#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node
{
	int data;
	struct Node *next;
} Node, *LinkedList;

typedef struct Graph_LinkedList
{
	LinkedList edges[MAX_SIZE];
	int n;
} Graph_LinkedList;

LinkedList insert_node(LinkedList head, int value);

void init_graph(Graph_LinkedList *g, int n);

void insert_graph(Graph_LinkedList *g, int a, int x, int y);

void output_graph(Graph_LinkedList *g);

void clear_graph(Graph_LinkedList *g);