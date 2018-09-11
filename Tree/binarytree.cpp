#include <string.h>
#include "binarytree.h"

Node* init(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void clear(Node *node)
{
	if (node->lchild != NULL)
	{
		clear(node->lchild);
	}
	if (node->rchild != NULL)
	{
		clear(node->rchild);
	}
	free(node);
}

void preorder(Node *node)
{
	printf("%d ", node->data);
	if (node->lchild != NULL)
	{
		preorder(node->lchild);
	}
	if (node->rchild != NULL)
	{
		preorder(node->rchild);
	}
}

void inorder(Node *node)
{
	if (node->lchild != NULL)
	{
		inorder(node->lchild);
	}
	printf("%d ", node->data);
	if (node->rchild != NULL)
	{
		inorder(node->rchild);
	}
}

void postorder(Node *node)
{
	if (node->lchild != NULL)
	{
		postorder(node->lchild);
	}
	if (node->rchild != NULL)
	{
		postorder(node->rchild);
	}
	printf("%d ", node->data);
}

Node* build_demo()
{
	Node *node = init(1);
	node->lchild = init(2);
	node->rchild = init(3);
	node->lchild->lchild = init(4);
	node->lchild->rchild = init(5);
	node->rchild->lchild = init(6);
	node->rchild->rchild = init(7);
	return node;
}

Node* build_demo(char pre_str[], char in_str[], int len)
{
	Node *p = init(pre_str[0] - '0');
	int pos = strchr(in_str, pre_str[0]) - in_str;
	if (pos > 0)
	{
		p->lchild = build_demo(pre_str + 1, in_str, pos);
	}
	if (len - pos - 1)
	{
		p->rchild = build_demo(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
	}
	return p;
}