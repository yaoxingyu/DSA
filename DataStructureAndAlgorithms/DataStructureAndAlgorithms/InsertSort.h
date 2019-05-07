#pragma once

void InsertSort(int a[], int n)
{
	if (n <= 1)
	{
		return;
	}

	for (size_t i = 1; i < n; i++)
	{
		int pos = i;
		for (size_t j = i-1; j >=0 ; j--)
		{
			if (a[pos] < a[j])
			{
				int tmp = a[pos];
				a[pos] = a[j];
				a[j] = tmp;
				pos = j;
			}
			else
			{
				break;
			}
		}
	}
}