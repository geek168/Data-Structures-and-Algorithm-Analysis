#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *lchild, *rchild, *father;
} Node;

Node* init(int value, Node *father);

Node* insert(Node *node, int value);

Node* search(Node *node, int value);

Node* predecessor(Node *node);

Node* successor(Node *node);

void remove_node(Node *delete_node);

int delete_tree(Node *node, int value);

void in_order_reversal(Node *node);

void clear(Node *node);