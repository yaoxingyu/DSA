#pragma once

#include "Common.h"
#include <list>

class Graph
{
public:
	Graph(){}
	~Graph(){}

private:
	int cnt; // 顶点个数
	std::list<int> adj; // 邻接表
};
