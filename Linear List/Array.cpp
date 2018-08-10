#include "array.h"

void init(Vector *vector, int size)
{
	vector->data = (int *)malloc(sizeof(int)*size);
	vector->size = size;
	vector->length = 0;
}

void expand(Vector *vector)
{
	int *old_data = vector->data;
	vector->size = vector->size * 2;
	vector->data = (int *)malloc(sizeof(int)*vector->size);
	for (int i = 0; i < vector->length; i++)
	{
		vector->data[i] = old_data[i];
	}
	free(old_data);
}

int insert(Vector *vector, int loc, int value)
{
	if (loc <0 || loc>vector->length)
	{
		return ERROR;
	}
	if (vector->length == vector->size)
	{
		expand(vector);
	}

	for (int i = vector->length; i > loc; i--)
	{
		vector->data[i] = vector->data[i - 1];
	}
	vector->data[loc] = value;
	vector->length++;
	return OK;
}

int delete_node(Vector *vector, int loc)
{
	if (loc < 0 || loc>vector->length)
	{
		return ERROR;
	}

	for (int i = loc; i < vector->length - 1; i++)
	{
		vector->data[i] = vector->data[i + 1];
	}
	vector->length--;
	return OK;
}

int search(Vector *vector, int value)
{
	for (int i = 0; i < vector->length; i++)
	{
		if (vector->data[i] == value)
		{
			return OK;
		}
	}
	return ERROR;
}

void print(Vector *vector)
{
	for (int i = 0; i < vector->length; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%d", vector->data[i]);
	}
	printf("\n");
}

void clear(Vector *vector)
{
	free(vector->data);
	free(vector);
}