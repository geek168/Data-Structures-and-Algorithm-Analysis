#include "trietree.h"

Trie new_node()
{
	Trie t = (TrieNode *)malloc(sizeof(TrieNode));
	t->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		t->childs[i] = NULL;
	}
	t->is_terminal = 0;
	return t;
}

void insert(Trie t, char *pattern)
{
	for (int i = 0; i < strlen(pattern); i++)
	{
		if (t->childs[pattern[i] - BASE] == NULL)
		{
			t->childs[pattern[i] - BASE] = new_node();
		}
		t = t->childs[pattern[i] - BASE];
	}
	t->is_terminal = 1;
}

int find(Trie t, char *pattern)
{
	for (int i = 0; i < strlen(pattern); i++)
	{
		if (t->childs[pattern[i] - BASE] == NULL)
		{
			return 0;
		}
		t = t->childs[pattern[i] - BASE];
	}
	return t->is_terminal;
}

void clear(Trie t)
{
	if (t != NULL)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (t->childs[i] != NULL)
			{
				clear(t->childs[i]);
			}
		}
		free(t->childs);
		free(t);
	}
}