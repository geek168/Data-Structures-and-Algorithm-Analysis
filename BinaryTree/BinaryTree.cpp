// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tree.h"

int main()
{
	/* sample data input
	6
	8 5 9 4 6 3
	1
	5
	*/
	Node *binarytree = NULL;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int v;
		scanf("%d", &v);
		binarytree = insert(binarytree, v);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);
		delete_tree(binarytree, v);
	}
	in_order_reversal(binarytree);
	clear(binarytree);
    return 0;
}

