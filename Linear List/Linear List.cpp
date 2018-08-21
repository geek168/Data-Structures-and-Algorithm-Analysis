// Linear List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "array.h"
//#include "linkedlist.h"
//#include "josephus.h"
#include "intersect.h"

int main()
{
#pragma region array
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
#pragma endregion

#pragma region linkedlist
	//LinkedList linkedlist = NULL;
	//int m;
	//scanf("%d\n", &m);
	//int t, loc, val;
	//for (int i = 0; i < m; i++)
	//{
	//	scanf("%d", &t);
	//	if (t == 1)
	//	{
	//		scanf(" %d %d", &loc, &val);
	//		Node *node = (Node *)malloc(sizeof(Node));
	//		node->data = val;
	//		node->next = NULL;
	//		linkedlist = insert(linkedlist, node, loc);
	//	}
	//	else if (t == 2)
	//	{
	//		scanf(" %d", &loc);
	//		linkedlist = delete_node(linkedlist, loc);
	//	}
	//	else if (t == 3)
	//	{
	//		linkedlist = reverse(linkedlist);
	//	}
	//	else
	//	{
	//		output(linkedlist);
	//	}
	//}
	//clear(linkedlist);
#pragma endregion

#pragma region josephus
	/*LinkedList linkedlist = NULL;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = i;
		node->next = NULL;
		linkedlist = insert_josephus(linkedlist, node, i - 1);
	}
	output_josephus(linkedlist, m);*/
#pragma endregion


	LinkedList head = NULL;
	LinkedList list_one = NULL;
	LinkedList list_two = NULL;
	int m, v;
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &v);
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = v;
		node->next = NULL;
		list_one = insert_intersect(list_one, node);
	}
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &v);
		Node *node = (Node *)malloc(sizeof(Node));
		node->data = v;
		node->next = NULL;
		list_two = insert_intersect(list_two, node);
	}

	head = intersect(head, list_one, list_two);
	int count = 0;
	if (head != NULL)
	{
		Node *current_node = head;
		count = 1;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
			count++;
		}
	}
	printf("%d\n", count);
	output_intersect(head);

	clear_intersect(head);
	clear_intersect(list_one);
	clear_intersect(list_two);

    return 0;
}

