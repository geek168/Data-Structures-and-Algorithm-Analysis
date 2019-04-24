// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "array.h"
#include "linkedlist.h"
#include "floodfill.h"
#include "prim.h"

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

	//int n, m, k;
	//scanf("%d %d", &n, &m);
	//Graph_LinkedList *g = (Graph_LinkedList *)malloc(sizeof(Graph_LinkedList));
	//init_graph(g, n);
	//for (int i = 0; i < m; ++i) {
	//	int x, y;
	//	scanf("%d %d", &x, &y);
	//	insert_graph(g, 1, x, y);
	//}
	//scanf("%d", &k);
	//bfs(g, k);
	//clear_graph(g);
	//return 0;


	///*
	//input:
	//11 10
	//0 1
	//0 2
	//1 2
	//1 3
	//2 3
	//4 5
	//4 6
	//7 8
	//8 9
	//8 10
	//*/
	//Graph_floodfill *g = (Graph_floodfill *)malloc(sizeof(Graph_floodfill));
	//int n, m;
	//scanf("%d %d", &n, &m);
	//init_floodfill(g, n);
	//for (int i = 0; i < m; i++)
	//{
	//	int a, b;
	//	scanf("%d %d", &a, &b);
	//	insert_floodfill(g, a, b);
	//}
	//floodfill(g);
	//free(g);

	/*
	input:
	5 7
	0 1 75
	0 2 9
	1 2 95
	1 3 51
	2 3 19
	2 4 42
	3 4 31
	0
	*/
	int n, m;
	scanf("%d %d", &n, &m);
	Graph_prim *g = (Graph_prim *)malloc(sizeof(Graph_prim));
	init_prim(g, n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		insert_prim(g, a, b, c);
	}
	int v;
	scanf("%d", &v);
	printf("%d\n", prim(g, v));
	free(g);

    return 0;
}

