// Dijkstra.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
int inf = 999999;
struct node {
	int num;
	int dist;
	node *prev;
	bool operator < (const node &x)const { //重载运算符，使得dist越小的node优先级越大
		return dist > x.dist;
	}
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
	//write your code her
	priority_queue<node> Q;
	vector<node> dis;
	node u,tmp;
	for (int i = 0; i < adj.size(); i++) {
		tmp.num = i;
		tmp.dist = inf;
		tmp.prev = NULL;
		dis.push_back(tmp);
	}
	dis[s].dist = 0;
	dis[s].num = s;
	Q.push(dis[s]);
	while (!Q.empty()) {
		u = Q.top();
		Q.pop();
		for (int i = 0; i < adj[u.num].size(); i++) {
			if (dis[adj[u.num][i]].dist > dis[u.num].dist + cost[u.num][i]) { //对U的邻边进行松弛
				dis[adj[u.num][i]].dist = dis[u.num].dist + cost[u.num][i];
				dis[adj[u.num][i]].prev = &u;
				Q.push(dis[adj[u.num][i]]);
			}

		}
	}
	if (dis[t].dist != inf)
		return dis[t].dist;
	else
	    return -1;
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
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, cost, s, t);
}
