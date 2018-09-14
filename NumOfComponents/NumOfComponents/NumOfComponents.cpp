// NumOfComponents.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int IsVisit[1000] = { 0 };
void DFS(vector<vector<int> > &adj, int v) {
	IsVisit[v] = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		if (IsVisit[adj[v][i]] != 1)
			DFS(adj,adj[v][i]);
	}
}
int number_of_components(vector<vector<int> > &adj) {
	int res = 0;
	//write your code here
	int i, j, visited = 1;
	for (i = 0; i<adj.size(); i++) {
		if (IsVisit[i] == 0) {
			IsVisit[i] = visited;
			for (j = 0; j < adj[i].size(); j++) {
				if (IsVisit[adj[i][j]] != visited) {
					DFS(adj, adj[i][j]);
				}
			}
			res++;
		}
	}
	return res;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	std::cout << number_of_components(adj);
}
