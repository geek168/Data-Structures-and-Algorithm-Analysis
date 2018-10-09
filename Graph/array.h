#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Graph
{
	int mat[MAX_SIZE][MAX_SIZE];
	int n;
} Graph;

void init(Graph *g, int n);

void insert(Graph *g, int a, int x, int y);

void output(Graph *g);

