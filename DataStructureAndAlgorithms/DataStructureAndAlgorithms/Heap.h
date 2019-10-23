#pragma once

#include "Common.h"

enum ChildType
{
	LEFT_CHILD,
	RIGHT_CHILD,
};

class Heap
{
public:
	Heap(int c)
	{
		capacity = c;
		count = 0;
		a = new int[capacity]();// �򵥴��������ʼ��Ϊ[0, 0, 0, 0, 0, ..., 0], ��֧�ֲ���>0������
	}
	~Heap()
	{
		delete[] a;
	}

public:
	bool Insert(int data)
	{
		if (count >= capacity)
		{
			return false;
		}

		a[count] = data;

		if (count)
		{
			_heapfy(count);
		}

		count++;
		return true;
	}

	void EraseRoot()
	{
		if (count == 0)
		{
			return;
		}

		a[0] = 0;
		if (count == 1)
		{
			count--;
			return;
		}

		_swap(0, count - 1);
		count--;
		_topHeapfy(a, count, 0);
	}

public:

	static void Sort(int a[], int n)
	{
		_buildHeap(a, n);
		int k = n - 1;
		while (k)
		{
			_swap(a, 0, k);
			_topHeapfy(a, k--, 0);
		}
	}

private:

	// ����
	static void _buildHeap(int a[], int n)
	{
		// ��Ϊ�����϶��¶ѻ�������Ҷ�ӽڵ㲻��Ҫ�ѻ���ֻ��ӵ����ڶ��㿪ʼ����
		for (int i = (n-1)/2; i >=0; --i)
		{
			_topHeapfy(a, n, i);
		}
	}

	// ���϶��¶ѻ�
	static void _topHeapfy(int a[], int n, int index)
	{
		while (true)
		{
			int maxPos = index;
			int left = index * 2 + 1;
			int right = index * 2 + 2;

			if (left < n && a[maxPos] < a[left])
			{
				maxPos = left;
			}

			if (right < n && a[maxPos] < a[right])
			{
				maxPos = right;
			}

			if (maxPos == index)
			{
				break;
			}

			_swap(a, index, maxPos);
			index = maxPos;
		}
	}

	static void _swap(int a[], int index1, int index2)
	{
		int tmp = a[index1];
		a[index1] = a[index2];
		a[index2] = tmp;
	}

private:

	bool _isNull(int index)
	{
		return a[index] == 0;
	}

	int _getParentIndex(int index)
	{
		return (index - 1) / 2;
	}

	int _getChildIndex(int index, ChildType ct)
	{
		int childIndex = 0;
		if (ct == LEFT_CHILD)
		{
			childIndex = index * 2 + 1;
		}
		else
		{
			childIndex = index * 2 + 2;
		}
		return childIndex + 1 > capacity ? -1 : childIndex;
	}

	void _swap(int index1, int index2)
	{
		SAFE_TEST_RET(index1 > count, true) // count++ ��_heapfyִ��֮��Ż�ִ�У����Դ�ʱ��count��ʵ������С1
		SAFE_TEST_RET(index2 > count, true)

		int tmp = a[index1];
		a[index1] = a[index2];
		a[index2] = tmp;
	}

	// ���¶��϶ѻ�
	void _heapfy(int index)
	{
		if (!index)
		{
			return;
		}

		int parentIndex = _getParentIndex(index);
		if (a[index] > a[parentIndex])
		{
			_swap(index, parentIndex);
			_heapfy(parentIndex);
		}
	}

private:
	int capacity;
	int* a;
	int count;
};
