#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *lchild, *rchild;
} Node;

Node* init(int data);

void clear(Node *node);

void preorder(Node *node);

void inorder(Node *node);

void postorder(Node *node);

Node* build_demo();

Node* build_demo(char pre_str[], char in_str[], int len);
