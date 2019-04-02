#pragma once


void BubbleSort(int a[], int n)
{
	int tmp = 0;
	for (int i = 0; i < n-1; i++)
	{
		bool bFlag = false;
		for (int j = 0; j < n-1-i; j++)
		{
			if (a[j]>a[j+1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				bFlag = true;
			}
		}
		if (!bFlag)
		{
			break;
		}
	}
}












// 冒泡排序，每轮遍历从左到右两两比较，把最大的往后面换