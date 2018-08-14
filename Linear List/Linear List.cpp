// Linear List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "array.h"

int main()
{
	Vector *vector = (Vector *)malloc(sizeof(Vector));
	init(vector, 10);

	int m;
	scanf("%d\n", &m);

	int t, loc, val, ret;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf(" %d %d", &loc, &val);
			ret = insert(vector, loc, val);
		}
		else if (t == 2)
		{
			scanf(" %d", &loc);
			ret = delete_node(vector, loc);
		}
		else
		{
			print(vector);
		}

		if (ret == 0)
		{
			printf("failed\n");
		}
		else if (ret == 1)
		{
			printf("success\n");
		}
	}

	clear(vector);

    return 0;
}

