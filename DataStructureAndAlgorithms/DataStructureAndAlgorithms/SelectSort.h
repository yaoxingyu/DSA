#pragma once

void SelectSort(int a[], int n)
{
	if (n <= 1)
	{
		return;
	}

	for (int i = 0; i < n-1; i++)
	{
		int pos = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[pos])
			{
				pos = j;
			}
		}

		if (pos != i)
		{
			int tmp = a[pos];
			a[pos] = a[i];
			a[i] = tmp;
		}
	}
}






// 将数组分为有序和无序两部分，每次从无序部分找出最小的，放到有序部分的末尾