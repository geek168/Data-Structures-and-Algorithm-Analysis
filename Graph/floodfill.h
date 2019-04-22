#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct Graph_floodfill
{
	int n;
	int color[MAX_N];
	int mat[MAX_N][MAX_N];
} Graph_floodfill;

void init_floodfill(Graph_floodfill *g, int size);

void insert_floodfill(Graph_floodfill *g, int a, int b);

void floodfill(Graph_floodfill *g);