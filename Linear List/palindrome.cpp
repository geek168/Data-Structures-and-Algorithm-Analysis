#include "palindrome.h"


PalindromeNode* new_node(char value, PalindromeNode *next)
{
	PalindromeNode *node = (PalindromeNode *)malloc(sizeof(PalindromeNode));
	node->data = value;
	node->next = next;
	return node;
}

void clear(PalindromeNode *node)
{
	while (node != NULL)
	{
		PalindromeNode *temp = node;
		node = node->next;
		free(temp);
	}
}

int is_palindrome(PalindromeNode *node)
{
	if (node == NULL)
	{
		return 0;
	}
	if (node->next == NULL)
	{
		return 1;
	}

	PalindromeNode *fast = node;
	PalindromeNode *low = node;
	PalindromeNode *prev = NULL;
	int t = 0;
	while (fast->next != NULL)
	{
		t = 0;
		fast = fast->next;
		if (fast->next != NULL)
		{
			fast = fast->next;
			t = 1;
		}
		PalindromeNode *temp = low;
		low = low->next;
		temp->next = prev;
		prev = temp;
	}

	if (t == 1)
	{
		low = low->next;
	}

	int ret = 1;
	while (low != NULL)
	{
		if (low->data == prev->data)
		{
			low = low->next;
			prev = prev->next;
		}
		else
		{
			ret = 0;
			break;
		}
	}
	return ret;
}