#include "prim.h"

void init_prim(Graph_prim *g, int size)
{
	g->n = size;
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			g->mat[i][j] = INF;
		}
	}
}

void insert_prim(Graph_prim *g, int x, int y, int weight)
{
	g->mat[x][y] = weight;
	g->mat[y][x] = weight;
}

int prim(Graph_prim *g, int v)
{
	int total = 0;
	for (int i = 0; i < g->n; i++)
	{
		g->dist[i] = INF;
		g->visited[i] = 0;
	}

	g->dist[v] = 0;
	for (int i = 0; i < g->n; i++)
	{
		int min_dist = INF, min_vertex;
		for (int j = 0; j < g->n; j++)
		{
			if (!g->visited[j] && g->dist[j] < min_dist)
			{
				min_dist = g->dist[j];
				min_vertex = j;
			}
		}

		printf("%d\n", min_dist);
		g->visited[min_vertex] = 1;
		total += min_dist;
		for (int j = 0; j < g->n; j++)
		{
			if (!g->visited[j] && g->mat[min_vertex][j] < g->dist[j])
			{
				g->dist[j] = g->mat[min_vertex][j];
			}
		}
	}

	return total;
}