#pragma once
// LRU ������̭�㷨
// ǰ���ͺ��ָ����Ϊ�˽���㴮��˫�������У�hnext ָ����Ϊ�˽���㴮��ɢ�б��������
// hashʵ��O(1)���ң�˫������ʵ��O(1)�����ɾ���ڵ�

struct LruNode
{
	LruNode* pPrev;  // ǰ��
	LruNode* pNext;  // ���
	LruNode* pHashNext; // ��ϣ��ɢ�г�ͻ����
	int data;
};

