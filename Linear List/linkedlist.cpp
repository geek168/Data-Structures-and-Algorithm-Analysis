#include "linkedlist.h"

LinkedList insert(LinkedList head, Node *node, int index)
{
	if (head == NULL)
	{
		if (index != 0)
		{
			return head;
		}

		head = node;
		return head;
	}

	if (index == 0)
	{
		node->next = head;
		head = node;
		return head;
	}

	Node *current_node = head;
	int count = 0;
	while (current_node->next != NULL && count < index - 1)
	{
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1)
	{
		node->next = current_node->next;
		current_node->next = node;
	}
	return head;
}

LinkedList delete_node(LinkedList head, int index)
{
	if (head == NULL)
	{
		return head;
	}

	Node *current_node = head;
	if (index == 0)
	{
		head = current_node->next;
		free(current_node);
		return head;
	}

	int count = 0;
	while (current_node->next != NULL && count < index - 1)
	{
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1)
	{
		Node *delete_node = current_node->next;
		current_node->next = delete_node->next;
		free(delete_node);
	}
	return head;
}

LinkedList reverse(LinkedList head)
{
	if (head == NULL)
	{
		return head;
	}

	Node *current_node, *next_node;
	current_node = head->next;
	head->next = NULL;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		current_node->next = head;
		head = current_node;
		current_node = next_node;
	}

	return head;
}

void output(LinkedList head)
{
	if (head == NULL)
	{
		return;
	}

	Node *current_node = head;
	int count = 0;
	while (current_node != NULL)
	{
		if (count > 0)
		{
			printf(" ");
		}
		printf("%d", current_node->data);
		current_node = current_node->next;
		count++;
	}
	printf("\n");
}

void clear(LinkedList head)
{
	if (head == NULL)
	{
		return;
	}

	Node *current_node = head;
	while (current_node != NULL)
	{
		Node *delete_node = current_node;
		current_node = current_node->next;
		free(delete_node);
	}
}