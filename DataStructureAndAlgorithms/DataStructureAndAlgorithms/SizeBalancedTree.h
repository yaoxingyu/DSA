#pragma once

#include<iostream>

// Size Balanced Tree(简称SBT)是一种平衡二叉搜索树, 通过如下性质来保持平衡:

// 1. root->left.size >= MAX(root->right->left.size, root->right->right.size);

// 2. root->right.size >= MAX(root->left->left.size, root->left->right.size);

// 即：任意节点的子树大小不小于其兄弟节点的左右子树大小

// 相比其他平衡二叉树，SBT使用size作为旋转标记，可以在O(logn)的时间复杂度内获得rank

#define SAFE_TEST_RET(REALVALUE, TESTVALUE) if((REALVALUE) == (TESTVALUE)) return;
#define SAFE_TEST_RET_VAL(REALVALUE, TESTVALUE, RETVALUE) if((RETVALUE) == (TESTVALUE)) return RETVALUE;

class SBNode
{
public:
	SBNode() :left(NULL), right(NULL), size(0), data(0) {}

public:
	SBNode * left;
	SBNode* right;
	int size;
	int data;
};

class SBTree
{
public:
	SBTree() :root(NULL) {}
	~SBTree() {}

public:
	static void InsertNode(int data, SBNode* &pRoot)
	{
		if (pRoot == NULL)
		{
			pRoot = new SBNode;
			pRoot->data = data;
			pRoot->size = 1;
		}
		else
		{
			if (data < pRoot->data)
			{
				InsertNode(data, pRoot->left);
			}
			else
			{
				InsertNode(data, pRoot->right);
			}
			pRoot->size += 1;
			MainTain(pRoot, data >= pRoot->data);
		}
	}

	static bool EraseNode(int key, SBNode* &pRoot)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, false);
		if (key == pRoot->data)
		{
			pRoot->size--;
			SBNode* pTmp;
			if (pRoot->left != NULL && pRoot->right == NULL)
			{
				pTmp = pRoot;
				pRoot = pTmp->left;
				delete pTmp;
			}
			else if (pRoot->left == NULL && pRoot->right != NULL)
			{
				pTmp = pRoot;
				pRoot = pRoot->right;
				delete pTmp;
			}
			else if (pRoot->left == NULL && pRoot->right == NULL)
			{
				delete pRoot;
				pRoot = NULL;
			}
			else if (pRoot->left != NULL && pRoot->right != NULL)
			{
				pTmp = pRoot->left;
				while (pTmp->right != NULL)
				{
					pTmp = pTmp->right;
				}
				pRoot->data = pTmp->data;
				EraseNode(pTmp->data, pRoot->left);
			}
			return true;
		}
		else if (key < pRoot->data)
		{
			if (EraseNode(key, pRoot->left))
			{
				pRoot->size--;
			}
		}
		else
		{
			if (EraseNode(key, pRoot->right))
			{
				pRoot->size--;
			}
		}
	}

	static SBNode* FindNode(int key, SBNode* pRoot)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, NULL);
		if (key == pRoot->data)
		{
			return pRoot;
		}
		else if (key < pRoot->data)
		{
			return FindNode(key, pRoot->left);
		}
		else
			return FindNode(key, pRoot->right);
	}

	static SBNode* SelectNode(int rank, SBNode* pRoot)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, NULL);
		int curRank = SizeOf(pRoot->left) + 1;
		if (curRank == rank)
		{
			return pRoot;
		}
		else
		{
			if (curRank < rank)
			{
				return SelectNode(rank - curRank, pRoot->right);
			}
			else
				return SelectNode(rank, pRoot->left);
		}
	}

	static int Rank(int key, SBNode* pRoot)
	{
		SAFE_TEST_RET_VAL(pRoot, NULL, 0);
		if (pRoot->data == key)
		{
			return SizeOf(pRoot->left) + 1;
		}
		else if (key < pRoot->data)
		{
			return Rank(key, pRoot->left);
		}
		else
			return Rank(key, pRoot->right) + SizeOf(pRoot->left) + 1;
	}

	static void PrintNodes(SBNode* pRoot)
	{
		SAFE_TEST_RET(pRoot, NULL);
		if (pRoot->left != NULL)
		{
			PrintNodes(pRoot->left);
		}
		std::cout << pRoot->data << std::endl;
		if (pRoot->right != NULL)
		{
			PrintNodes(pRoot->right);
		}
	}

private:
	static int SizeOf(SBNode* pNode)
	{
		SAFE_TEST_RET_VAL(pNode, NULL, 0);
		return pNode->size;
	}

	static void RightRotate(SBNode* &pNode)
	{
		SAFE_TEST_RET(pNode, NULL);
		SBNode* pTop = pNode->left;
		pNode->left = pTop->right;
		pTop->right = pNode;

		pTop->size = pNode->size;
		pNode->size = SizeOf(pNode->left) + SizeOf(pNode->right) + 1;

		pNode = pTop;
	}

	static void LeftRotate(SBNode* &pNode)
	{
		SAFE_TEST_RET(pNode, NULL);
		SBNode* pTop = pNode->right;
		pNode->right = pTop->left;
		pTop->left = pNode;

		pTop->size = pNode->size;
		pNode->size = SizeOf(pNode->left) + SizeOf(pNode->right) + 1;

		pNode = pTop;
	}

	// 平衡维护
	static void MainTain(SBNode* &pNode, bool rightDeeper)
	{
		SAFE_TEST_RET(pNode, NULL);
		if (!rightDeeper)
		{
			SAFE_TEST_RET(pNode->left, NULL);
			if (SizeOf(pNode->left->left) > SizeOf(pNode->right))
			{
				RightRotate(pNode);
			}
			else if (SizeOf(pNode->left->right) > SizeOf(pNode->right))
			{
				LeftRotate(pNode->left);
				RightRotate(pNode);
			}
			else
				return;
		}
		else
		{
			SAFE_TEST_RET(pNode->right, NULL);
			if (SizeOf(pNode->right->right) > SizeOf(pNode->left))
			{
				LeftRotate(pNode);
			}
			else if (SizeOf(pNode->right->left) > SizeOf(pNode->left))
			{
				RightRotate(pNode->right);
				LeftRotate(pNode);
			}
			else
				return;
		}

		MainTain(pNode->left, false);
		MainTain(pNode->right, true);
		MainTain(pNode, true);
		MainTain(pNode, false);
	}

public:
	SBNode * root;
};
