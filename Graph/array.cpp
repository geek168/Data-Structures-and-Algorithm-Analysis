#include "array.h"

void init(Graph *g, int n)
{
	if (n > MAX_SIZE)
	{
		n = MAX_SIZE;
	}
	g->n = n;
	memset(g->mat, 0, sizeof(g->mat));
}

void insert(Graph *g, int a, int x, int y)
{
	if (x < 0 || x >= g->n || y < 0 || y >= g->n)
	{
		return;
	}

	if (a == 0) //有向图
	{
		g->mat[x][y] = 1;
	}
	else if(a == 1) //无向图
	{
		g->mat[x][y] = 1;
		g->mat[y][x] = 1;
	}
}

void output(Graph *g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("%d ", g->mat[i][j]);
		}
		printf("\n");
	}
}
