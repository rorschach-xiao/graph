// BFS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
int infinite = 999999;
int distance(vector<vector<int> > &adj, int s, int t) {
	//write your code here
	int u;
	queue<int> Q;
	vector<int> dist(adj.size(), infinite);
	dist[s] = 0;
	Q.push(s);
	while (Q.empty() != true) {
		u = Q.front();
		Q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			if (dist[adj[u][i]] == infinite) {
				Q.push(adj[u][i]);
				dist[adj[u][i]] = dist[u] + 1;
			}
		}
	}
	if (dist[t] != infinite)
		return dist[t];
	else
        return -1;
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
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, s, t);
}
