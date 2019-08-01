#include "BinarySearch.h"

int binarySearch(int *data, int n, int val)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (val < data[mid])
		{
			right = mid - 1;
		}
		else if(val > data[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

int searchFirstNumber(int *data, int n, int val)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (val < data[mid])
		{
			right = mid - 1;
		}
		else if(val > data[mid])
		{
			left = mid + 1;
		}
		else
		{
			if (mid == 0 || data[mid - 1] != val)
			{
				return mid;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	return -1;
}

int searchLastNumber(int *data, int n, int val)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (val < data[mid])
		{
			right = mid - 1;
		}
		else if(val > data[mid])
		{
			left = mid + 1;
		}
		else
		{
			if ((mid == n - 1) || data[mid + 1] != val)
			{
				return mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	return -1;
}

int searchFirstGreaterThanOrEqual(int *data, int n, int val)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (val > data[mid])
		{
			left = mid + 1;
		}
		else
		{
			if ((mid == 0) || data[mid - 1] < val)
			{
				return mid;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	return -1;
}

int searchLastLessThanOrEqual(int *data, int n, int val)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (val < data[mid])
		{
			right = mid - 1;
		}
		else
		{
			if ((mid == n - 1) || data[mid + 1] > val)
			{
				return mid;
			}
			else
			{
				left = mid + 1;
			}
		}
	}

	return -1;
}