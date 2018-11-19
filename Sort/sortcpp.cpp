#include "sort.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_sort(int *data, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i - 1; i >= 0; j--)
		{
			if (data[j] > data[j + 1])
			{
				swap(&data[j], &data[j + 1]);
			}
			else
			{
				break;
			}
		}
	}
}

void bubble_sort(int *data, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int swapped = 0;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(&data[j], &data[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}

void merge_sort(int *data, int l, int r)
{
	if (l == r)
	{
		return;
	}

	int mid = (l + r) / 2;
	merge_sort(data, l, mid);
	merge_sort(data, mid + 1, r);

	int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
	int x = l, y = mid + 1, loc = 0;
	while (x <= mid || y <= r)
	{
		if (x <= mid && (y > r || data[x] <= data[y]))
		{
			temp[loc] = data[x];
			x++;
		}
		else
		{
			temp[loc] = data[y];
			y++;
		}
		loc++;
	}

	for (int i = l; i <= r; i++)
	{
		data[i] = temp[i - l];
	}
	free(temp);
}

void printf(int *data, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i > 0)
		{
			printf(" ");
		}
		printf("%d", data[i]);
	}
}