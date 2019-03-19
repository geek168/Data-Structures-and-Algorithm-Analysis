// Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "heap.h"

int main()
{
	int arr[10] = { 12, 9, 30, 24, 30, 4, 55, 64, 22, 37 };
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	init(heap, 100);
	for (int i = 0; i < 10; i++) 
	{
		push(heap, arr[i]);
	}

	output(heap);
	pop(heap);
	output(heap);

	heap_sort(heap);
	output(heap);

	clear(heap);
	return 0;
}

