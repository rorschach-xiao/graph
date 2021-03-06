// NegetiveCycle.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using std::vector;
int inf = 999999;
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
	//write your code here
	vector<int> dist(adj.size(), inf);
	vector<int *> prev(adj.size(), NULL);
	int V = adj.size();
	int i=0, j, k;
	dist[0] = 0;
	while(i<V-1) {
		for (j = 0; j < V; j++) {
			for (k = 0; k < adj[j].size(); k++) {
				if (dist[adj[j][k]] > dist[j] + cost[j][k]) {//relax the edge(j,k)
					dist[adj[j][k]] = dist[j] + cost[j][k];
					prev[adj[j][k]] = &j;
				}
			}
		}
		i++;
	}
	for (j = 0; j < V; j++) {
		for (k = 0; k < adj[j].size(); k++) {
			if (dist[adj[j][k]] > dist[j] + cost[j][k]) {//relax the edge(j,k)
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cout << negative_cycle(adj, cost);
}
