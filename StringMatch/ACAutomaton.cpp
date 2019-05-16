#include "ACAutomaton.h"

Auomaton* new_auomaton_node()
{
	Auomaton *at = (Automaton *)malloc(sizeof(Auomaton));
	at->childs = (Auomaton **)malloc(sizeof(Auomaton *) * SIZE_auomaton);
	for (int i = 0; i < SIZE_auomaton; i++)
	{
		at->childs[i] = NULL;
	}
	at->fail = NULL;
	at->count = 0;
	return at;
}

void insert_auomaton(Auomaton* at, char *pattern)
{
	for (int i = 0; i < strlen(pattern); i++)
	{
		if (at->childs[pattern[i] - BASE_auomaton] == NULL)
		{
			at->childs[pattern[i] - BASE_auomaton] = new_auomaton_node();
		}
		at = at->childs[pattern[i] - BASE_auomaton];
	}
	at->count++;
}

void clear_auomaton(Auomaton* at)
{
	if (at != NULL)
	{
		for (int i = 0; i < SIZE_auomaton; i++)
		{
			if (at->childs[i] != NULL)
			{
				clear_auomaton(at->childs[i]);
			}
		}
		free(at->childs);
		free(at);
	}
}

void build_automaton(Automaton* root)
{
	root->fail = root;
	Auomaton *q[MAX_N * 20];
	int l = 0, t = 0;
	q[t++] = root;
	while (l < t)
	{
		Auomaton *now = q[l++];
		for (int i = 0; i < SIZE_auomaton; i++)
		{
			if (now->childs[i] != NULL)
			{
				Automaton *child = now->childs[i];
				if (now == root)
				{
					child->fail = root;
				}
				else
				{
					Auomaton *iter = now;
					while (iter != root && iter->fail->childs[i] == NULL)
					{
						iter = iter->fail;
					}
					if (iter->fail->childs[i] != NULL)
					{
						child->fail = iter->fail->childs[i];
					}
					else
					{
						child->fail = root;
					}
				}
				q[t++] = child;
			}
		}
	}
}

int match_count(Automaton* root, const char *buffer)
{
	int total = 0;
	Automaton *q = root;
	for (int i = 0; buffer[i]; i++)
	{
		while (q != root && q->childs[buffer[i] - BASE_auomaton] == NULL)
		{
			q = q->fail;
		}
		q = q->childs[buffer[i] - BASE_auomaton];
		if (q == NULL)
		{
			q = root;
		}
		Automaton *iter = q;
		while (iter != root)
		{
			total += iter->count;
			//iter->count = 0;
			iter = iter->fail;
		}
	}
	return total;
}