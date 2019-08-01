// Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearch.h"


int main()
{
	int data1[5] = { 1,3,4,5,6 };
	int a = binarySearch(data1, 5, 3);

	int data2[10] = { 1,3,4,5,6,8,8,8,11,18 };
	a = searchFirstNumber(data2, 10, 8);

	int data3[10] = { 1,3,4,5,6,8,8,8,11,18 };
	a = searchLastNumber(data3, 10, 8);

	int data4[5] = { 3,4,6,7,10 };
	a = searchFirstGreaterThanOrEqual(data4, 5, 5);

	int data5[5] = { 3,4,6,7,10 };
	a =  searchLastLessThanOrEqual(data5, 5, 5);

    return 0;
}

