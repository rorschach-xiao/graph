// SCCs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
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
vector<int>reverse_postorder(vector<vector<int>> &adj) {
	vector<vector<int>> adj_r(adj.size(),vector<int>());
	vector<int> used(adj.size(), 0);
	vector<int> order;
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			adj_r[adj[i][j]].push_back(i); //对原图取反
		}
	}
	for (int i = 0; i < adj_r.size(); i++) {
		dfs(adj_r, used, order, i);
	}
	return order;
}
void explore(vector<vector<int>>&adj,vector<int>&used, int v) {
	used[v] = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		if (used[adj[v][i]] == 0)
			explore(adj, used, adj[v][i]);
	}
	return;
}
int number_of_strongly_connected_components(vector<vector<int> > &adj) {
	vector<int> used(adj.size(), 0);
	vector<int> used_scc(adj.size(), 0);
	vector<int> order;
	int result = 0;
	//write your code here
	order = reverse_postorder(adj);
	std::reverse(order.begin(), order.end()); //将order中vertex从栈顶到栈底排序
	for (int i = 0; i < order.size(); i++) {
		if (used_scc[order[i]] == 0) {
			explore(adj, used_scc,order[i]);
			result++;
		}
	}
	return result;
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
	std::cout << number_of_strongly_connected_components(adj);
}

