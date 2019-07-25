#pragma once

struct Node {
	int data;
	Node* next;
	Node(int d):data(d), next(nullptr){}
} ;

Node* reverse(Node* pHead)
{
	Node* pCur = pHead;
	Node* pLast = nullptr;
	while (pCur != nullptr)
	{
		Node* pNext = pCur->next;
		pCur->next = pLast;
		pLast = pCur;
		pCur = pNext;
	}
	return pLast;
}