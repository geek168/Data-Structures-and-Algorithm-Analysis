#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

const int INF_dijkstra = 0x3f3f3f3f;

typedef struct Graph_dijkstra
{
	int n;
	int visited[MAX_N];
	int dist[MAX_N];
	int mat[MAX_N][MAX_N];
} Graph_dijkstra;

void init_dijkstra(Graph_dijkstra *g, int size);

void insert_dijkstra(Graph_dijkstra *g, int x, int y, int weight);

void dijkstra(Graph_dijkstra *g, int v);