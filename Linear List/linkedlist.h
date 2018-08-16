#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index);

LinkedList delete_node(LinkedList head, int index);

LinkedList reverse(LinkedList head);

void output(LinkedList head);

void clear(LinkedList head);