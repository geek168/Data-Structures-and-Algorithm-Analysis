#include <stdio.h>
#include <stdlib.h>

typedef struct PalindromeNode 
{
	char data;
	struct PalindromeNode *next;
} PalindromeNode;

int is_palindrome(PalindromeNode *node);

PalindromeNode* new_node(char value, PalindromeNode *next);

void clear(PalindromeNode *node);