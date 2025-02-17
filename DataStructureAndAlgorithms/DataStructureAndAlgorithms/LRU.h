#pragma once
// LRU 缓存淘汰算法
// 前驱和后继指针是为了将结点串在双向链表中，hnext 指针是为了将结点串在散列表的拉链中
// hash实现O(1)查找，双向链表实现O(1)的添加删除节点

struct LruNode
{
	LruNode* pPrev;  // 前驱
	LruNode* pNext;  // 后继
	LruNode* pHashNext; // 哈希表散列冲突链表
	int data;
};

