#include "floodfill.h"


void init_floodfill(Graph_floodfill *g, int size)
{
	g->n = size;
	for (int i = 0; i < g->n; i++)
	{
		g->color[i] = 0;
		for (int j = 0; j < g->n; j++)
		{
			g->mat[i][j] = 0;
		}
	}
}

void insert_floodfill(Graph_floodfill *g, int a, int b)
{
	g->mat[a][b] = 1;
	g->mat[b][a] = 1;
}

void floodfill(Graph_floodfill *g)
{
	int color_cnt = 0;
	int q[MAX_N];
	for (int i = 0; i < g->n; i++)
	{
		if (g->color[i] == 0)
		{
			color_cnt++;
			g->color[i] = color_cnt;
			int l = 0, r = 0;
			q[r++] = i;
			while (l < r)
			{
				int vertext = q[l++];
				for (int j = 0; j < g->n; j++)
				{
					if (g->mat[vertext][j] && g->color[j] == 0)
					{
						q[r++] = j;
						g->color[j] = color_cnt;
					}
				}
			}
		}
	}
	for (int i = 1; i <= color_cnt; i++)
	{
		printf("%d:", i);
		for (int j = 0; j < g->n; j++)
		{
			if (g->color[j] == i)
			{
				printf("%d ", j);
			}
		}
		printf("\n");
	}
}