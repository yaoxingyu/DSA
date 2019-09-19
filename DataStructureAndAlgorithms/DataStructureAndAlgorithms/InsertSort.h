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
				a[j + 1] = a[j]; // ��ð����ȿ��Խ�ʡ���ν�������
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





// �������Ϊ��������������֣�ÿ��ȡ���򲿷ֵ�ͷ���θ����򲿷ֵ�β��ʼ�Ƚϣ������С������λ�ã�����������ǰ�Ƚϣ�����������β���