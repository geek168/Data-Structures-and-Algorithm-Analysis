// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binarytree.h"

int main()
{
	/*Node *root = build_demo();
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	clear(root);*/

	char pre_str[] = "136945827";
	char in_str[] = "963548127";
	Node *root = build_demo(pre_str, in_str, _mbstrlen(pre_str));
	printf("%s\n", pre_str);
	printf("%s\n", in_str);
	postorder(root);
	printf("\n");
	clear(root);
    return 0;
}

