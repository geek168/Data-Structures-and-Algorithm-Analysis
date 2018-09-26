#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node
{
	char data;
	struct Node *lchild, *rchild;
} Node;

typedef struct Stack
{
	Node **data;
	int size, top;
} Stack;

typedef struct Queue
{
	Node **data;
	int head, tail, size;
} Queue;

Node* inittree(char data);

void cleartrees(Node *tree);

void initstack(Stack *stack, int size);

void expand(Stack *stack);

void push(Stack *stack, Node *data);

void pop(Stack *stack);

Node* top(Stack *stack);

int empty(Stack *stack);

void clearstack(Stack *stack);

void initqueue(Queue *queue, int size);

Node* dequeue(Queue *queue);

void enqueue(Queue *queue, Node *data);

void clearqueue(Queue *queue);

void levelorder(Node *tree, Queue *queue);
