// TopologicalSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
int IsVisit[100000] = { 0 };
void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
	//write your code here
	IsVisit[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (IsVisit[adj[x][i]] == 0)
			dfs(adj, used, order, adj[x][i]);
	}
	if (used[x] == 0) {
		order.push_back(x);
		used[x] = 1;
	}
	return;
}

vector<int> toposort(vector<vector<int> > adj) {
	vector<int> used(adj.size(), 0);
	vector<int> order;
	//write your code here
	for (int i = 0; i < adj.size(); i++) {
		dfs(adj, used, order, i);
	}
	return order;
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
	vector<int> order = toposort(adj);
	for (size_t i = 0; i <adj.size(); i++) {
		std::cout << order[adj.size()-i-1] + 1 << " ";
	}
}
