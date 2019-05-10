#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
#define BASE 'a'
#define SIZE 26

typedef struct TrieNode
{
	int is_terminal;
	struct TrieNode **childs;
} TrieNode, *Trie;

Trie new_node();

void insert(Trie t, char *pattern);

int find(Trie t, char *pattern);

void clear(Trie t);
