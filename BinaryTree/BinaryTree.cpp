// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tree.h"

int main()
{
	Node *binarytree = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		binarytree = insert(binarytree, k);
	}
	int v;
	scanf("%d", &v);
	if (search(binarytree, v) != NULL)
	{
		printf("search success!\n");
	}
	else
	{
		printf("search failed!\n");
	}
	in_order_reversal(binarytree);
	clear(binarytree);
    return 0;
}

