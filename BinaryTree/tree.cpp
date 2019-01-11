#include "tree.h"

Node* init(int value, Node *father)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->father = father;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

Node* insert(Node *node, int value)
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

Node* search(Node *node, int value)
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

Node* predecessor(Node *node)
{
	Node *temp = node->lchild;
	while (temp != NULL && temp->rchild != NULL)
	{
		temp = temp->rchild;
	}
	return temp;
}

Node* successor(Node *node)
{
	Node *temp = node->rchild;
	while (temp != NULL && temp->lchild != NULL)
	{
		temp = temp->lchild;
	}
	return temp;
}

// 删除度为 0 或者 1 的结点
// 因为 delete tree 的话最终是找到前驱最大或者后继最小的权值
// 替换被删结点，再把前驱最大或者后继最小删除
void remove_node(Node *delete_node)
{
	Node *temp = NULL;
	if (delete_node->lchild != NULL) //前驱最大可能有左孩子
	{
		temp = delete_node->lchild;
		temp->father = delete_node->father;
	}
	if (delete_node->rchild != NULL) //后继最小可能有有孩子
	{
		temp = delete_node->rchild;
		temp->father = delete_node->father;
	}
	if (delete_node->father->lchild == delete_node)
	{
		delete_node->father->lchild = temp;
	}
	else
	{
		delete_node->father->rchild = temp;
	}
	delete_node->lchild = NULL;
	delete_node->rchild = NULL;
	free(delete_node);
}

int delete_tree(Node *node, int value)
{
	Node *delete_node, *current_node;
	current_node = search(node, value);
	if (current_node == NULL)
	{
		return 0;
	}
	else
	{
		if (current_node->lchild != NULL)
		{
			delete_node = predecessor(current_node);
		}
		else if(current_node->rchild != NULL)
		{
			delete_node = successor(current_node);
		}
		else
		{
			delete_node = current_node;
		}
		current_node->data = delete_node->data;
		remove_node(delete_node);
		return 1;
	}
}

void in_order_reversal(Node *node)
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

void clear(Node *node)
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