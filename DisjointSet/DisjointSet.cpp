// DisjointSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "disjointset.h"


int main()
{
	/*
		input:
		5 4
		0 1
		1 2
		3 4
		2 3
	*/
	DisjointSet *dus = (DisjointSet *)malloc(sizeof(DisjointSet));
	int m, n;
	scanf("%d %d", &m, &n);
	init(dus, m);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		merge(dus, a, b);
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", dus->father[i]);
	}
	clear(dus);
    return 0;
}

