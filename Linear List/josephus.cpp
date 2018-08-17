#include "josephus.h"

LinkedList insert_josephus(LinkedList head, Node *node, int index)
{
	if (head == NULL)
	{
		if (index != 0)
		{
			return head;
		}
		head = node;
		node->next = head;
		return head;
	}
	if (index == 0)
	{
		node->next = head->next;
		head->next = node;
		return head;
	}

	Node *current_node = head->next;
	int count = 0;
	while (current_node != head && count < index - 1)
	{
		current_node = current_node->next;
		count++;
	}
	if (count == index - 1) 
	{
		node->next = current_node->next;
		current_node->next = node;
	}
	if (node == head->next)
	{
		head = node;
	}
	return head;
}

void output_josephus(LinkedList head, int m)
{
	Node *current_node = head;
	head = NULL;
	while (current_node->next != current_node)
	{
		for (int i = 1; i < m; i++)
		{
			current_node = current_node->next;
		}
		Node *delete_node = current_node->next;
		current_node->next = current_node->next->next;
		printf("%d ", delete_node->data);
		free(delete_node);
	}
	printf("%d\n", current_node->data);
	free(current_node);
}