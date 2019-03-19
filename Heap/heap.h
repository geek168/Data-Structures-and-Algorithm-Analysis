#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int *data;
	int size;
} Heap;

void swap(int *a, int *b);

void init(Heap *heap, int size);

void push(Heap *heap, int data);

void pop(Heap *heap);

void update(Heap *heap, int pos, int size);

void heap_sort(Heap *heap);

void output(Heap *heap);

void clear(Heap *heap);
