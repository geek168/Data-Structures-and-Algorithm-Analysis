#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node, *LinkedList;

LinkedList insert_josephus(LinkedList head, Node *node, int index);

void output_josephus(LinkedList head, int m);
