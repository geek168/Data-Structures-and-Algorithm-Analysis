// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sort.h"

int main()
{
	int data[10] = { 2,5,7,3,4,8,9,0,6,1 };
	//int data[5] = { 2,5,7,3,4 };
	int length = 10;
	//insert_sort(data, length);
	//bubble_sort(data, length);
	//merge_sort(data, 0, length - 1);
	//select_sort(data, length);
	quick_sort(data, 0, length - 1);
	printf(data, length);

    return 0;
}

