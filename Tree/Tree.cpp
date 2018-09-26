// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "binarytree.h"
//#include <ctype.h>
//#include "generalizedlist.h"
#include "generalizedlistlevelorder.h"

int main()
{
	/*Node *root = build_demo();
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	clear(root);*/

	//char pre_str[] = "136945827";
	//char in_str[] = "963548127";
	//Node *root = build_demo(pre_str, in_str, _mbstrlen(pre_str));
	//printf("%s\n", pre_str);
	//printf("%s\n", in_str);
	//postorder(root);
	//printf("\n");
	//clear(root);

	/*样例输入：A B C D E $*/
	/*样例输出：A(B(D,E),C)*/
	/*Queue *queue = (Queue *)malloc(sizeof(Queue));
	char t;
	int i = 0;
	while (scanf("%c", &t) != EOF && getchar() != '\n')
	{
		if (isalpha(t))
		{
			if (i == 0)
			{
				queue->data = t;
				queue->size = 1;
				queue->next = NULL;
			}
			else
			{
				queue = push(queue, t);
			}
			i++;
		}
	}
	if (queue->size > 0)
	{
		char *buffer = (char *)malloc(sizeof(char) * queue->size);
		Queue *temp = queue;
		i = 0;
		while (temp != NULL)
		{
			buffer[i] = temp->data;
			temp = temp->next;
			i++;
		}
		buffer[i] = '\0';

		Node *tree = build(buffer, 1, i);
		pre_order(tree);
		cleartree(tree);
		free(buffer);
	}
	clear(queue);*/

	/*样例输入：A(B(D),C)*/
	/*样例输出：A B C D*/
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	Stack *temp = (Stack *)malloc(sizeof(Stack));
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	initstack(stack, 20);
	initstack(temp, 3);
	int size = 0;

	char c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		size++;
		if (c != ')')
		{
			Node *n = inittree(c);
			push(stack, n);
		}
		else
		{
			while (top(stack)->data != '(')
			{
				if (top(stack)->data != ',')
				{
					push(temp, top(stack));
				}
				pop(stack);
			}
			pop(stack);// (
			push(temp, top(stack));
			pop(stack);// ( 前的字符
			int i = 0;
			Node *head;
			while (!empty(temp))
			{
				if (i == 0)
				{
					head = top(temp);
					pop(temp);
				}
				else if (i == 1)
				{
					head->lchild = top(temp);
					pop(temp);
				}
				else
				{
					head->rchild = top(temp);
					pop(temp);
				}
				i++;
			}
			push(stack, head);
		}
	}



	initqueue(queue, size);
	if (stack->top >= 0)
	{
		Node *tree = stack->data[0];
		levelorder(tree, queue);
		cleartrees(tree);
	}

	clearstack(stack);
	clearstack(temp);
	clearqueue(queue);

    return 0;
}


