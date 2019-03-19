#include "heap.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void init(Heap *heap, int size)
{
	heap->data = (int *)malloc(sizeof(int) * size);
	heap->size = 0;
}

void push(Heap *heap, int data)
{
	heap->data[heap->size] = data;
	int current = heap->size;
	int father = (current - 1) / 2;
	while (heap->data[current] > heap->data[father]) 
	{
		swap(&heap->data[current], &heap->data[father]);
		current = father;
		father = (current - 1) / 2;
	}
	heap->size++;
}

void pop(Heap *heap)
{
	swap(&heap->data[0], &heap->data[heap->size - 1]);
	heap->size--;
	update(heap, 0, heap->size);
}

void update(Heap *heap, int pos, int size)
{
	int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
	int max_value = pos;
	if (lchild < size && heap->data[lchild] > heap->data[max_value])
	{
		max_value = lchild;
	}
	if (rchild < size && heap->data[rchild] > heap->data[max_value])
	{
		max_value = rchild;
	}
	if (max_value != pos)
	{
		swap(&heap->data[pos], &heap->data[max_value]);
		update(heap, max_value, size);
	}
}

void heap_sort(Heap *heap)
{
	for (int i = heap->size - 1; i >= 1; i--)
	{
		swap(&heap->data[0], &heap->data[i]);
		update(heap, 0, i);
	}
}

void output(Heap *heap)
{
	for (int i = 0; i < heap->size; i++)
	{
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}

void clear(Heap *heap)
{
	free(heap->data);
	free(heap);
}