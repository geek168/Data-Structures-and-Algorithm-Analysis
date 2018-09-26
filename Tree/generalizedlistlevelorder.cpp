#include "generalizedlistlevelorder.h"

Node* inittree(char data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}

void cleartrees(Node *tree)
{
	if (tree->lchild != NULL)
	{
		cleartrees(tree->lchild);
	}
	if (tree->rchild != NULL)
	{
		cleartrees(tree->rchild);
	}
	free(tree);
}

void initstack(Stack *stack, int size)
{
	stack->data = (Node **)malloc(sizeof(Node *) * size);
	stack->size = size;
	stack->top = -1;
}

void expand(Stack *stack)
{
	Node **old_data = stack->data;
	stack->size = stack->size * 2;
	stack->data = (Node **)malloc(sizeof(Node *) * stack->size);
	for (int i = 0; i <= stack->top; i++)
	{
		stack->data[i] = old_data[i];
	}
	free(old_data);
}

void push(Stack *stack, Node *data)
{
	if (stack->top + 1 >= stack->size)
	{
		expand(stack);
	}
	stack->top++;
	stack->data[stack->top] = data;
}

void pop(Stack *stack)
{
	stack->top--;
}

Node* top(Stack *stack)
{
	return stack->data[stack->top];
}

int empty(Stack *stack)
{
	return stack->top < 0;
}

void clearstack(Stack *stack)
{
	free(stack->data);
	free(stack);
}

void initqueue(Queue *queue, int size)
{
	queue->size = size;
	queue->data = (Node **)malloc(sizeof(Node *) * size);
	queue->head = 0;
	queue->tail = -1;
}

Node* dequeue(Queue *queue)
{
	Node *i = queue->data[queue->head];
	queue->head++;
	return i;
}

void enqueue(Queue *queue, Node *data)
{
	queue->tail++;
	queue->data[queue->tail] = data;
}

void clearqueue(Queue *queue)
{
	free(queue->data);
	free(queue);
}

void levelorder(Node *tree, Queue *queue)
{
	int k = 0;
	enqueue(queue, tree);
	do
	{
		Node *i = dequeue(queue);
		if (i->lchild != NULL)
		{
			enqueue(queue, i->lchild);
		}
		if (i->rchild != NULL)
		{
			enqueue(queue, i->rchild);
		}
		if (k > 0)
		{
			printf(" ");
		}
		printf("%c", i->data);
		k++;
	} while (queue->head <= queue->tail);
}

