#include "generalizedlist.h"

Node* init(char data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void cleartree(Node *node)
{
	if (node->lchild != NULL)
	{
		cleartree(node->lchild);
	}
	if (node->rchild != NULL)
	{
		cleartree(node->rchild);
	}
	free(node);
}

Queue* push(Queue *head, char data)
{
	Queue *e = (Queue *)malloc(sizeof(Queue));
	e->data = data;
	e->next = NULL;
	Queue *current_node = head;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = e;
	head->size++;
	return head;
}

void clear(Queue *head)
{
	Queue *del = head;
	if (del->next != NULL)
	{
		head = del->next;
	}
	free(del);
}

Node *build(char str[], int index, int len)
{
	Node *p = init(str[index - 1]);
	if ((index * 2) <= len)
	{
		p->lchild = build(str, index * 2, len);
	}
	if ((index * 2 + 1) <= len)
	{
		p->rchild = build(str, index * 2 + 1, len);
	}
	return p;
}

void pre_order(Node *tree)
{
	printf("%c", tree->data);
	if (tree->lchild != NULL)
	{
		printf("(");
		pre_order(tree->lchild);
		if (tree->rchild == NULL)
		{
			printf(")");
		}
	}
	if (tree->rchild != NULL)
	{
		printf(",");
		pre_order(tree->rchild);
		if (tree->rchild->lchild != NULL) //如果子树结点大于6个补全当前结点最外层的括号
		{
			printf(")");
		}
		if (tree->rchild->lchild == NULL)
		{
			printf(")");
		}
	}

}