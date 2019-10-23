#pragma once
#include "Common.h"
#include<iostream>

class BTNode
{
public:
	BTNode(int v) :left(NULL), right(NULL), data(v) {}
	BTNode(BTNode* pLeft, BTNode* pRight, int v):left(pLeft), right(pRight), data(v){}

public:
	BTNode * left;
	BTNode* right;
	int data;
};

class BinaryTree
{
public:
	BinaryTree(BTNode* pRoot):root(pRoot){}
	~BinaryTree()
	{
		_ReleaseNode(root);
	}

public:
	static bool InsertNode(BTNode* &pRoot, int data)
	{
		if (pRoot == NULL)
		{
			pRoot = new BTNode(data);
			return true;
		}
		else
		{
			BTNode* pCur = pRoot;
			while (pCur != NULL)
			{
				if (pCur->data == data)
					return false;
				if (pCur->data < data)
				{
					if (pCur->right == NULL)
					{
						pCur->right = new BTNode(data);
						return true;
					}
					else
					{
						pCur = pCur->right;
					}
				}
				else
				{
					if (pCur->left == NULL)
					{
						pCur->left = new BTNode(data);
						return true;
					}
					else
					{
						pCur = pCur->left;
					}
				}
			}

			return true;
		}
	}

	static BTNode* FindNode(BTNode* pRoot, int data)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, NULL)
		while (pRoot != NULL)
		{
			if (pRoot->data == data)
			{
				return pRoot;
			}
			else if(pRoot->data < data)
			{
				pRoot = pRoot->right;
			}
			else
			{
				pRoot = pRoot->left;
			}
		}
	}

	static bool EraseNode(BTNode* &pRoot, int data)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, false)
		BTNode* p = pRoot;
		BTNode* pp = NULL;
		while (p != NULL && p->data != data)
		{
			pp = p;
			if (p->data < data)
			{
				p = p->right;
			}
			else
			{
				p = p->left;
			}
		}

		if (p == NULL)
		{
			return false;
		}

		// 要删除的节点有两个子节点, 找到右子树的最小节点取代它
		if (p->left != NULL && p->right != NULL)
		{
			BTNode* pRMin = p->right;
			BTNode* pRMinP = p;
			while (pRMin->left != NULL)
			{
				pRMinP = pRMin;
				pRMin = pRMin->left;
			}
			
			// data exchange
			p->data = pRMin->data;
			// wait to delete
			p = pRMin;
			pp = pRMinP;
		}

		// 删除节点是叶子节点或者仅有一个子节点
		BTNode* pChild = p->left ? p->left : p->right;
		if (pp == NULL)
		{
			pRoot = pChild;
		}
		else if(pp->right == p)
		{
			pp->right = pChild;
		}
		else
		{
			pp->left = pChild;
		}
		delete p;
		return true;
	}

	static void PrintNodes(BTNode* pRoot)
	{
		SAFE_TEST_RET(pRoot, NULL)
		if (pRoot->left != NULL)
		{
			PrintNodes(pRoot->left);
		}
		std::cout << pRoot->data << " ";
		if (pRoot->right != NULL)
		{
			PrintNodes(pRoot->right);
		}
	}

	static int GetHight(BTNode* pRoot)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, 0)

		if (pRoot->left == NULL && pRoot->right == NULL)
		{
			return 1;
		}
		else
		{
			int leftHight = GetHight(pRoot->left);
			int rightHight = GetHight(pRoot->right);
			return  leftHight > rightHight ? leftHight + 1 : rightHight + 1;
		}
	}

private:
	void _ReleaseNode(BTNode* pRoot)
	{
		SAFE_TEST_RET(pRoot, NULL)
			if (pRoot->left)
			{
				_ReleaseNode(pRoot->left);
			}

		if (pRoot->right)
		{
			_ReleaseNode(pRoot->right);
		}

		delete pRoot;
	}

private:
	BTNode * root;
};