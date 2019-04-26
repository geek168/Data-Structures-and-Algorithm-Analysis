#include "dijkstra.h"

void init_dijkstra(Graph_dijkstra *g, int size)
{
	g->n = size;
	for (int i = 0; i < g->n; ++i) 
	{
		for (int j = 0; j < g->n; j++) 
		{
			g->mat[i][j] = INF_dijkstra;
		}
	}
}

void insert_dijkstra(Graph_dijkstra *g, int x, int y, int weight)
{
	g->mat[x][y] = weight;
	g->mat[y][x] = weight;
}

void dijkstra(Graph_dijkstra *g, int v)
{
	for (int i = 0; i < g->n; i++)
	{
		g->visited[i] = 0;
		g->dist[i] = INF_dijkstra;
	}
	g->dist[v] = 0;
	for (int i = 0; i< g->n; i++)
	{
		int min_dist = INF_dijkstra, min_vertex;
		for (int j = 0; j < g->n; j++)
		{
			if (!g->visited[j] && g->dist[j] < min_dist)
			{
				min_dist = g->dist[j];
				min_vertex = j;
			}
		}
		g->visited[min_vertex] = 1;
		for (int j = 0; j < g->n; j++)
		{
			if (!g->visited[j] && min_dist + g->mat[min_vertex][j] < g->dist[j])
			{
				g->dist[j] = min_dist + g->mat[min_vertex][j];
			}
		}
	}
}