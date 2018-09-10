// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binarytree.h"

int main()
{
	Node *root = build_demo();
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	clear(root);
    return 0;
}

