#include "disjointset.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void init(DisjointSet *s, int size)
{
	s->father = (int *)malloc(sizeof(int) * size);
	s->rank = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		s->father[i] = i;
		s->rank[i] = 0;
	}
}

int find_set(DisjointSet *s, int data)
{
	if (s->father[data] != data)
	{
		s->father[data] = find_set(s, s->father[data]);
	}
	return s->father[data];
}

int merge(DisjointSet *s, int a, int b)
{
	int ancestor1 = find_set(s, a);
	int ancestor2 = find_set(s, b);
	if (ancestor1 != ancestor2)
	{
		if (s->rank[ancestor1] > s->rank[ancestor2])
		{
			swap(&ancestor1, &ancestor2);
		}
		s->father[ancestor1] = ancestor2;
		s->rank[ancestor2] = max(s->rank[ancestor2], s->rank[ancestor1] + 1);
		return 1;
	}
	return 0;
}

void clear(DisjointSet *s)
{
	free(s->father);
	free(s->rank);
	free(s);
}

