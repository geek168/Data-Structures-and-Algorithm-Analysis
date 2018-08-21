#include "intersect.h"

LinkedList insert_intersect(LinkedList head, Node *node)
{
	/*
		集合依次递增，所以统一集合内不会存在相同元素
	*/

	if (head == NULL)
	{
		head = node;
		return head;
	}

	//if (node->data <= head->data)
	if (node->data < head->data)
	{
		node->next = head;
		head = node;
		return head;
	}

	Node *current_node = head;
	while (current_node != NULL)
	{
		if (node->data > current_node->data)
		{
			if (current_node->next == NULL)
			{
				current_node->next = node;
				break;
			}
			/*else if (current_node->next != NULL && node->data <= current_node->next->data)*/
			else if (current_node->next != NULL && node->data < current_node->next->data)
			{
				node->next = current_node->next;
				current_node->next = node;
				break;
			}
			else if (current_node->next != NULL && node->data == current_node->next->data)
			{
				break;
			}
			else
			{
				current_node = current_node->next;
			}
		}
		else if (node->data == current_node->data)
		{
			//current_node->next = node;
			break;
		}
	}
	return head;
}

void output_intersect(LinkedList head)
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

void clear_intersect(LinkedList head)
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

LinkedList intersect(LinkedList head, LinkedList list_one, LinkedList list_two)
{
	if (list_one == NULL || list_two == NULL)
	{
		return NULL;
	}

	Node *current_node_one = list_one;
	Node *current_node_two = list_two;
	while (current_node_one != NULL)
	{
		while (current_node_two != NULL)
		{
			if (current_node_one->data == current_node_two->data)
			{
				Node *node = (Node *)malloc(sizeof(Node));
				node->data = current_node_one->data;
				node->next = NULL;
				if (head == NULL)
				{
					head = node;
				}
				else
				{
					Node *current_node = head;
					while (current_node->next != NULL)
					{
						current_node = current_node->next;
					}
					current_node->next = node;
				}
				current_node_one = current_node_one->next;
				current_node_two = current_node_two->next;
			}
			else if (current_node_one->data > current_node_two->data)
			{
				current_node_two = current_node_two->next;
			}
			else if (current_node_one->data < current_node_two->data)
			{
				current_node_one = current_node_one->next;
			}

			if (current_node_one == NULL)
			{
				break;
			}
		}

		if (current_node_two == NULL)
		{
			break;
		}
	}

	return head;
}