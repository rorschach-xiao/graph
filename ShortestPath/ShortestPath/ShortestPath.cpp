// ShortestPath.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
int IsVisit[1000] = { 0 };
void DFS(vector<vector<int> > &adj, vector<int> &shortest, int v) {
	IsVisit[v] = 1;
	for (int i = 0; i < adj[v].size(); i++) {
		if (shortest[adj[v][i]] != 0)
			shortest[adj[v][i]] = 0;
		if(IsVisit[adj[v][i]]==0)
		   DFS(adj, shortest, adj[v][i]);
	}
}
void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
	//write your code here
	int V = adj.size();
	int i = 0, u,HasNegetiveCycle=0;
	vector<int *> prev(adj.size(), NULL);
	queue<int> Q;
	distance[s] = 0;
	while (i < V - 1) {
		int InQueue[1000] = { 0 };
		int IsVisit[1000] = { 0 };
		if (InQueue[s] == 0) {
			Q.push(s);
			InQueue[s] = 1;
		}
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			reachable[u] = 1;
			InQueue[u] = 0;
			if (IsVisit[u] == 0) {
				for (int j = 0; j < adj[u].size(); j++) {
					if (InQueue[adj[u][j]] == 0&&IsVisit[adj[u][j]]==0) {
						Q.push(adj[u][j]);
						InQueue[adj[u][j]] = 1;
					}
					if (distance[adj[u][j]] > distance[u] + cost[u][j]) {
						distance[adj[u][j]] = distance[u] + cost[u][j];
						prev[adj[u][j]] = &u;
					}
				}
				IsVisit[u] = 1;
			}
			else
				break;
		}
		i++;
	}
	int InQueue[1000] = { 0 };
	int IsVisit[1000] = { 0 };
	int v;
	if (InQueue[s] == 0) {
		Q.push(s);
		InQueue[s] = 1;
	}
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		InQueue[u] = 0;
		if (IsVisit[u] == 0) {
			for (int j = 0; j < adj[u].size(); j++) {
				if (InQueue[adj[u][j]] == 0 && IsVisit[adj[u][j]] == 0) {
					Q.push(adj[u][j]);
					InQueue[adj[u][j]] = 1;
				}
				if (distance[adj[u][j]] > distance[u] + cost[u][j]) {
					distance[adj[u][j]] = distance[u] + cost[u][j];
					shortest[adj[u][j]] = 0; 
					v = adj[u][j];
					HasNegetiveCycle = 1;//存在负环
					goto A;
				}
			}
			IsVisit[u] = 1;
		}
		else
		    break;
	}

A:  if (HasNegetiveCycle == 1) {
	    for (int i = 0; i < V; i++) {//将找到的节点向前回溯V次，得到的节点一点在负环中
		v = *prev[v];
	    }
		DFS(adj, shortest, v); //用DFS遍历所有与v相连的节点
	}
		
}

int main() {
	int n, m, s;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cin >> s;
	s--;
	vector<long long> distance(n, std::numeric_limits<long long>::max());
	vector<int> reachable(n, 0);
	vector<int> shortest(n, 1);
	shortest_paths(adj, cost, s, distance, reachable, shortest);
	for (int i = 0; i < n; i++) {
		if (!reachable[i]) {
			std::cout << "*\n";
		}
		else if (!shortest[i]) {
			std::cout << "-\n";
		}
		else {
			std::cout << distance[i] << "\n";
		}
	}
}