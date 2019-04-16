#include <stdio.h>
#include <stdlib.h>

typedef struct DisjointSet
{
	int *father;
	int *rank;
} DisjointSet;

void swap(int *a, int *b);

int max(int a, int b);

void init(DisjointSet *s, int size);

int find_set(DisjointSet *s, int data);

int merge(DisjointSet *s, int a, int b);

void clear(DisjointSet *s);

