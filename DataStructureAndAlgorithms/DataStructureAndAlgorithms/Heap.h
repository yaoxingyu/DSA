#pragma once

#include "Common.h"

class Heap
{
public:
	Heap(int c)
	{
		capacity = c;
		count = 0;
		a = new int[capacity]();
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

		a[count++] = data;
		return true;
	}

private:

	int _getParentIndex(int index)
	{
		return (index - 1) / 2;
	}

	int _getChildIndex(int index, bool isLeft)
	{
		int childIndex = 0;
		if (isLeft)
		{
			childIndex = index * 2 + 1;
		}
		else
		{
			childIndex = index * 2 + 2;
		}
		return childIndex + 1 > capacity ? -1 : childIndex;
	}

	void _heapfy()
	{

	}

private:
	int capacity;
	int* a;
	int count;
};
