// BalancedBinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sbtree.h"

int main()
{

	init_NIL();
	SBTNode *binarytree = NULL;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int n;
		scanf("%d", &n);
		binarytree = insert_tree(binarytree, n);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int n;
		scanf("%d", &n);
		if (delete_tree(binarytree, n))
		{
			printf("delete success!\n");
		}
		else
		{
			printf("delete failed!\n");
		}
	}
	output(binarytree);
	clear(binarytree);

    return 0;
}

