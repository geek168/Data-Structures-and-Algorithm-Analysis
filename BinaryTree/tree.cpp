#include "tree.h"

Node* init(int value, Node* father)
{
	Node* node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->father = father;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

Node* insert(Node* node, int value)
{
	if (node == NULL)
	{
		node = init(value, node);
	}
	else if(value < node->data)
	{
		if (node->lchild == NULL)
		{
			node->lchild = init(value, node);
		}
		else
		{
			insert(node->lchild, value);
		}
	}
	else if(value > node->data)
	{
		if (node->rchild == NULL)
		{
			node->rchild = init(value, node);
		}
		else
		{
			insert(node->rchild, value);
		}
	}
	return node;
}

Node* search(Node* node, int value)
{
	if (node == NULL || node->data == value)
	{
		return node;
	}
	else if(value < node->data)
	{
		if (node->lchild == NULL)
		{
			return NULL;
		}
		else
		{
			search(node->lchild, value);
		}
	}
	else if(value > node->data)
	{
		if (node->rchild == NULL)
		{
			return NULL;
		}
		else
		{
			search(node->rchild, value);
		}
	}
}

void in_order_reversal(Node* node)
{
	if (node->lchild != NULL)
	{
		in_order_reversal(node->lchild);
	}
	printf("%d ", node->data);
	if (node->rchild != NULL)
	{
		in_order_reversal(node->rchild);
	}
}

void clear(Node* node)
{
	if (node != NULL)
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
}