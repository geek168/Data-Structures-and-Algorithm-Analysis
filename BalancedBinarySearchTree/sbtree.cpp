#include "sbtree.h"

SBTNode *NIL;

void init_NIL()
{
	NIL = (SBTNode *)malloc(sizeof(SBTNode));
	NIL->data = 0;
	NIL->size = 0;
	NIL->lchild = NIL;
	NIL->rchild = NIL;
	NIL->father = NULL;
}

SBTNode* init(int data, int size, SBTNode *father)
{
	SBTNode *node = (SBTNode *)malloc(sizeof(SBTNode));
	node->data = data;
	node->size = size;
	node->father = father;
	node->lchild = NIL;
	node->rchild = NIL;
	return node;
}

SBTNode * left_rotate(SBTNode * node) 
{
	SBTNode *temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild->father = node;
	temp->father = node->father;
	temp->lchild = node;
	node->father = temp;
	temp->size = node->size;
	node->size = node->lchild->size + node->rchild->size + 1;
	return temp;
}

SBTNode * right_rotate(SBTNode * node) 
{
	SBTNode *temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild->father = node;
	temp->father = node->father;
	node->father = temp;
	temp->rchild = node;
	temp->size = node->size;
	node->size = node->lchild->size + node->rchild->size + 1;
	return temp;
}

SBTNode* insert_tree(SBTNode *node, int data)
{
	if (node == NULL) 
	{
		node = init(data, 1, NULL);
		return node;
	}
	if (search(node, data) != NIL) 
	{
		return node;
	}
	return add_node(node, data);
}

int delete_tree(SBTNode *node, int data)
{

	SBTNode *current_node, *delete_node;
	current_node = search(node, data);
	if (current_node == NIL)
	{
		return ERROR;
	}

	if (current_node->lchild != NIL)
	{
		delete_node = predecessor(current_node);
	}
	else if (current_node->rchild != NIL)
	{
		delete_node = successor(current_node);
	}
	else
	{
		delete_node = current_node;
	}
	current_node->data = delete_node->data;
	remove_node(delete_node);

	return OK;
}

SBTNode* search(SBTNode *node, int data)
{
	if (node == NIL || NIL->data == data)
	{
		return node;
	}

	if (data < node->data)
	{
		search(node->lchild, data);
	}
	else if(data > node->data)
	{
		search(node->rchild, data);
	}
}

SBTNode* predecessor(SBTNode *node)
{
	SBTNode *temp = node->lchild;
	while (temp != NIL && temp->rchild != NIL)
	{
		temp = temp->rchild;
	}
	return temp;
}

SBTNode* successor(SBTNode *node)
{
	SBTNode *temp = node->rchild;
	while (temp != NIL && temp->lchild != NIL)
	{
		temp = temp->lchild;
	}
	return temp;
}

SBTNode * maintain(SBTNode * node, int flag) 
{
	if (flag == 0)
	{
		if (node->lchild->lchild->size > node->rchild->size)
		{
			node = right_rotate(node);
		}
		else if (node->lchild->rchild->size > node->rchild->size)
		{
			node->lchild = left_rotate(node->lchild);
			node = right_rotate(node);
		}
		else
		{
			return node;
		}
	}
	else
	{
		if (node->rchild->rchild->size > node->lchild->size)
		{
			node = left_rotate(node);
		}
		else if (node->rchild->lchild->size > node->lchild->size)
		{
			node->rchild = right_rotate(node->rchild);
			node = left_rotate(node);
		}
		else
		{
			return node;
		}
	}

	node->lchild = maintain(node->lchild, 0);
	node->rchild = maintain(node->rchild, 1);
	node = maintain(node, 0);
	node = maintain(node, 1);
	return node;
}

void remove_node(SBTNode *delete_node)
{
	SBTNode * temp = NIL;
	if (delete_node->lchild != NIL) 
	{
		temp = delete_node->lchild;
		temp->father = delete_node->father;
		delete_node->lchild = NIL;
	}
	if (delete_node->rchild != NIL) 
	{
		temp = delete_node->rchild;
		temp->father = delete_node->father;
		delete_node->rchild = NIL;
	}
	if (delete_node->father->lchild == delete_node) 
	{
		delete_node->father->lchild = temp;
	}
	else 
	{
		delete_node->father->rchild = temp;
	}
	temp = delete_node;
	while (temp != NULL) {
		temp->size--;
		temp = temp->father;
	}
	delete_node->lchild = NIL;
	delete_node->rchild = NIL;
	free(delete_node);
}

SBTNode* add_node(SBTNode *node, int data)
{
	node->size++;
	if (data > node->data) 
	{
		if (node->rchild == NIL) 
		{
			node->rchild = init(data, 1, node);
		}
		else 
		{
			node->rchild = add_node(node->rchild, data);
		}
	}
	else 
	{
		if (node->lchild == NIL) 
		{
			node->lchild = init(data, 1, node);
		}
		else 
		{
			node->lchild = add_node(node->lchild, data);
		}
	}
	return maintain(node, data > node->data);
}

void clear(SBTNode *node)
{
	if (node != NIL) 
	{
		if (node->lchild != NIL)
		{
			clear(node->lchild);
		}
		if (node->rchild != NIL) 
		{
			clear(node->rchild);
		}
		free(node);
	}
}

void output(SBTNode *node)
{
	if (node->lchild != NIL)
	{
		output(node->lchild);
	}
	printf("%d ", node->data);
	if (node->rchild != NIL)
	{
		output(node->rchild);
	}
}
