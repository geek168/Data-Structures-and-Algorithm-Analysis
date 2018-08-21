#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node, *LinkedList;

LinkedList insert_intersect(LinkedList head, Node *node);

void output_intersect(LinkedList head);

void clear_intersect(LinkedList head);

LinkedList intersect(LinkedList head, LinkedList list_one, LinkedList list_two);
