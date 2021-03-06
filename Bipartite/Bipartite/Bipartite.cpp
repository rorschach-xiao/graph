// Bipartite.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
	//write your code here
	int u,s=0;
	queue<int> Q;
	vector<int> color(adj.size(), -1);//0为白色,1为黑色,-1为未染色
	color[s] = 0;
	Q.push(s);
	while (Q.empty() != 1) {
		u = Q.front();
		Q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
				if (color[adj[u][i]] == -1) {
					color[adj[u][i]] = !color[u];
					Q.push(adj[u][i]);
				}
				else if (color[adj[u][i]] == color[u]) {
					return 0;
				}
		}
	}

	return 1;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	std::cout << bipartite(adj);
}
