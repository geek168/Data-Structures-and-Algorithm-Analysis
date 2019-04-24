#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

const int INF = 0x3f3f3f3f;

typedef struct Graph_prim
{
	int n;
	int visited[MAX_N];
	int dist[MAX_N];
	int mat[MAX_N][MAX_N];
} Graph_prim;

void init_prim(Graph_prim *g, int size);

void insert_prim(Graph_prim *g, int x, int y, int weight);

int prim(Graph_prim *g, int v);