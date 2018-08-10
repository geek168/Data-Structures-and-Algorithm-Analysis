#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector
{
	int size;
	int length;
	int *data;
} Vector;

void init(Vector *vector, int size);

void expand(Vector *vector);

int insert(Vector *vector, int loc, int value);

int delete_node(Vector *vector, int loc);

int search(Vector *vector, int value);

void print(Vector *vector);

void clear(Vector *vector);