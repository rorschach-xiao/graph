// Acyclic.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int IsVisit[1000] = { 0 }; //0表示节点还没有被发现，1表示节点正在被处理，2表示节点已经处理完毕
int flag = 0;//用于存储是否有环
void DFS(vector<vector<int> > &adj, int v) {
	IsVisit[v] = 1;//节点v正在被处理
	for (int i = 0; i < adj[v].size(); i++) {
		if (IsVisit[adj[v][i]] == 0)//若没有被访问，则对该节点进行DFS
			DFS(adj, adj[v][i]);
		else if (IsVisit[adj[v][i]] == 1) {
			flag = 1;//表示存在环
			return;
		}
	}
	IsVisit[v] = 2;//节点v访问结束
}

int acyclic(vector<vector<int> > &adj) {
	//write your code here
	for(int i=0;i<adj.size();i++)
	    DFS(adj, i);
	return flag;
}


int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	std::cout << acyclic(adj);
}

