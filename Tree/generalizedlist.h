#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	char data;
	int size;
	struct Queue *next;
} Queue;

typedef struct Node
{
	char data;
	struct Node *lchild, *rchild;
} Node;

Node* init(char data);

void cleartree(Node *node);

Queue* push(Queue *head, char data);

void clear(Queue *head);

Node *build(char str[], int index, int len);

void pre_order(Node *tree);