#pragma once

#include "Common.h"
#include <list>
#include <iostream>

class Graph
{
public:
	Graph(int cnt)
	{
		this->cnt = cnt;
		adj = new std::list<int>[cnt];
	}
	~Graph(){}
public:
	// 无向图
	void AddEdge(int s, int t)
	{
		adj[s].push_back(s);
		adj[t].push_back(s);
	}

public:
	void Print(int* pre, int start, int target)
	{
		if (pre[target] != -1 && target != start)
		{
			std::cout << target << "<==";
			Print(pre, start, pre[target]);
		}
	}

public:
	// deep first search
	void DFS(int start, int target)
	{
		found = false;
		bool* visited = new bool[cnt];
		int* pre = new int[cnt];
		for (int i = 0; i < cnt; i++)
		{
			visited[i] = false;
			pre[i] = -1;
		}
		_dfs(start, target, visited, pre);
		Print(pre, start, target);
	}
private:
	void _dfs(int start, int target, bool* visited, int* pre)
	{
		if (found)
		{
			return;
		}

		visited[start] = true;
		if (start == target)
		{
			found = true;
			return;
		}

		for (auto itr = adj[start].begin(); itr != adj[start].end(); itr++)
		{
			int cur = *itr;
			if (visited[cur] == false)
			{
				pre[cur] = start;
				_dfs(cur, target, visited, pre);
			}
		}
	}

private:
	int cnt; // 顶点个数
	std::list<int>* adj; // 邻接表
	static bool found;
};
bool Graph::found = false;
