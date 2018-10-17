// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "array.h"
#include "linkedlist.h"

int main()
{
	/*Graph *g = (Graph *)malloc(sizeof(Graph));
	int v, e;
	scanf("%d %d", &v, &e);
	init(g, v);
	for (int i = 0; i < e; i++)
	{
		int a, x, y;
		scanf("%d %d %d", &a, &x, &y);
		insert(g, a, x, y);
	}
	output(g);
	free(g);*/

	//Graph_LinkedList *g = (Graph_LinkedList *)malloc(sizeof(Graph_LinkedList));
	//int v, e;
	//scanf("%d %d", &v, &e);
	//init_graph(g, v);
	//for (int i = 0; i < e; i++)
	//{
	//	int a, x, y;
	//	scanf("%d %d %d", &a, &x, &y);
	//	insert_graph(g, a, x, y);
	//}
	//output_graph(g);
	//clear_graph(g);


	//Graph_LinkedList *g = (Graph_LinkedList *)malloc(sizeof(Graph_LinkedList));
	//int v, e;
	//scanf("%d %d", &v, &e);
	//init_graph(g, v);
	//for (int i = 0; i < e; i++)
	//{
	//	int x, y;
	//	scanf("%d %d", &x, &y);
	//	insert_graph(g, 1, x, y);
	//}
	//int k;
	//scanf("%d", &k);
	//dfs(g, k);
	//clear_graph(g);

	int n, m, k;
	scanf("%d %d", &n, &m);
	Graph_LinkedList *g = (Graph_LinkedList *)malloc(sizeof(Graph_LinkedList));
	init_graph(g, n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		insert_graph(g, 1, x, y);
	}
	scanf("%d", &k);
	bfs(g, k);
	clear_graph(g);
	return 0;

    return 0;
}

