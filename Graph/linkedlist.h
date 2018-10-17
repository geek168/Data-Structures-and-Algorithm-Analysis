#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int visited[MAX_SIZE];
} Graph_LinkedList;

typedef struct Queue
{
	int *data;
	int head, tail, size;
} Queue;

LinkedList insert_node(LinkedList head, int value);

void init_graph(Graph_LinkedList *g, int n);

void init_queue(Queue *q, int size);

void insert_graph(Graph_LinkedList *g, int a, int x, int y);

void output_graph(Graph_LinkedList *g);

void clear_graph(Graph_LinkedList *g);

void clear_queue(Queue *q);

void push(Queue *q, int data);

void pop(Queue *q);

int empty_queue(Queue *q);

int front(Queue *q);

void dfs(Graph_LinkedList *g, int vertex);

void bfs(Graph_LinkedList *g, int vertex);