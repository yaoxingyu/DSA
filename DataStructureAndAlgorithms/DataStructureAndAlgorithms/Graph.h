#pragma once

#include "Common.h"
#include <list>

class Graph
{
public:
	Graph(){}
	~Graph(){}

private:
	int cnt; // �������
	std::list<int> adj; // �ڽӱ�
};
