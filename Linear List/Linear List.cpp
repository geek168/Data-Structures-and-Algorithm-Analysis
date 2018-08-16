// Linear List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "array.h"
#include "linkedlist.h"

int main()
{
	//Vector *vector = (Vector *)malloc(sizeof(Vector));
	//init(vector, 10);

	//int m;
	//scanf("%d\n", &m);

	//int t, loc, val, ret;
	//for (int i = 0; i < m; i++)
	//{
	//	scanf("%d", &t);
	//	if (t == 1)
	//	{
	//		scanf(" %d %d", &loc, &val);
	//		ret = insert(vector, loc, val);
	//	}
	//	else if (t == 2)
	//	{
	//		scanf(" %d", &loc);
	//		ret = delete_node(vector, loc);
	//	}
	//	else
	//	{
	//		print(vector);
	//	}

	//	if (ret == 0)
	//	{
	//		printf("failed\n");
	//	}
	//	else if (ret == 1)
	//	{
	//		printf("success\n");
	//	}
	//}

	//clear(vector);


	LinkedList linkedlist = NULL;
	int m;
	scanf("%d\n", &m);
	int t, loc, val;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf(" %d %d", &loc, &val);
			Node *node = (Node *)malloc(sizeof(Node));
			node->data = val;
			node->next = NULL;
			linkedlist = insert(linkedlist, node, loc);
		}
		else if (t == 2)
		{
			scanf(" %d", &loc);
			linkedlist = delete_node(linkedlist, loc);
		}
		else if (t == 3)
		{
			linkedlist = reverse(linkedlist);
		}
		else
		{
			output(linkedlist);
		}
	}

	clear(linkedlist);

    return 0;
}

