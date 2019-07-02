#pragma once


int partition(int a[], int low, int high)
{
	int i = low;
	int flag = a[high];
	for (int j = low; j < high; j++)
	{
		if (a[j] < flag)
		{
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
			i++;
		}
	}

	int tmp = a[i];
	a[i] = flag;
	a[high] = tmp;
	return i;
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
