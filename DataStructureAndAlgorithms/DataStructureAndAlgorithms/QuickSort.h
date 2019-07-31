#pragma once


int partition(int a[], int low, int high)
{
	int flag = a[high];
	for (int j = low; j < high; j++)
	{
		if (a[j] < flag)
		{
			int tmp = a[j];
			a[j] = a[low];
			a[low] = tmp;
			low++;
		}
	}

	int tmp = a[low];
	a[low] = flag;
	a[high] = tmp;
	return low;
}

void QuickSort(int a[], int low, int high)
{
	if (low >= high)
	{
		return;
	}

	int mid = partition(a, low, high);

	QuickSort(a, low, mid-1);
	QuickSort(a, mid + 1, high);
}


// O(n)ÕÒµÚK´óÔªËØ
int FindK(int a[], int low, int high, int k)
{
	int mid = partition(a, low, high);
	if (mid+1 == k)
	{
		return a[mid];
	}
	else if(mid+1 < k)
	{
		return FindK(a, mid + 1, high, k - mid - 1);
	}
	else
	{
		return FindK(a, low, mid - 1, k);
	}
}

