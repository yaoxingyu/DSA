#include <iostream>
#include <vector>

#include "LadderStep.h"
#include "BubbleSort.h"
#include "InsertSort.h"
#include "SelectSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	// 爬楼梯问题
	//cout << LadderStep::ClimbLadder(7) << endl;

	// 冒泡排序
	int a[] = {9,8,7,6,5,4,3,2,1,100,53,44,75};
	//BubbleSort(a, sizeof(a)/4);
	//InsertSort(a, sizeof(a) / 4);
	//SelectSort(a, sizeof(a) / 4);

	// 归并排序
	//const int length = sizeof(a) / sizeof(int);
	//int tmp[length];
	//MergeSort(a, tmp, 0, length-1);

	// 快速排序
	//QuickSort(a, 0, length-1);
	//int k = FindK(a, 0, length - 1, 12);

	// 单链表逆转
	Node* pCur = nullptr;
	Node* pHead = nullptr;
	for (size_t i = 0; i < 10; i++)
	{
		Node* pNode = new Node(i);
		if (pCur == nullptr)
		{
			pCur = pNode;
			pHead = pNode;
		}
		else
		{
			pCur->next = pNode;
			pCur = pNode;
		}
	}

	pHead = reverse(pHead);

	return 0;
}