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












// ð������ÿ�ֱ��������������Ƚϣ������������滻