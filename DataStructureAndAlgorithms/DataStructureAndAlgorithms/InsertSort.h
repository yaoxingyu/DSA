#pragma once

void InsertSort(int a[], int n)
{
	if (n <= 1)
	{
		return;
	}

	for (int i = 1; i < n; i++)
	{
		int value = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] > value)
			{
				a[j + 1] = a[j]; // 跟冒泡相比可以节省两次交换操作
			}
			else
			{
				a[j + 1] = value;
				break;
			}
		}
	}
}

/*void InsertSort(int a[], int n)
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
}*/





// 将数组分为有序和无序两部分，每次取无序部分的头依次跟有序部分的尾开始比较，如果较小，交换位置，继续依次往前比较，否则结束当次插入