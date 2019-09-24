#pragma once
#include<iostream>
#include<cmath>
#include "QuickSort.h"

int Bsearch(int a[], int low, int high, int value)
{
	static int count = 0;
	count++;
	std::cout << "BinarySearch Count: " << count << std::endl;
	int mid = low + (high - low) / 2;
	if (mid == low)
	{
		return -1;
	}

	if (a[mid] == value)
	{
		return mid;
	}
	else if (a[mid] < value)
	{
		return Bsearch(a, mid, high, value);
	}
	else
		return Bsearch(a, low, mid, value);
}

int BinarySearch(int a[], int n, int value)
{
	QuickSort(a, 0, n - 1);
	return Bsearch(a, 0, n - 1, value);
}

float _Sqrt(float low, float high, float origin)
{
	float mid = (high - low) / 2 + low;
	float fValue = mid * mid;
	float diff = fValue - origin;
	if ((diff > 0 && diff < 0.0001) || (diff<0 && diff>-0.0001))
	{
		return mid;
	}
	else
	{
		if (fValue > origin)
		{
			return _Sqrt(low, mid, origin);
		}
		else
		{
			return _Sqrt(mid, high, origin);
		}
	}
}

float Sqrt(float origin)
{

	if (origin < 0)
	{
		return -1;
	}
	else if (origin < 1)
	{
		return _Sqrt(0, origin, origin);
	}
	else
		return _Sqrt(1, origin, origin);
}
