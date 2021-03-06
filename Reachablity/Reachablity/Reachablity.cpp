// Reachablity.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"	
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int IsVisit[1000]= { 0 };

int reach(vector<vector<int> > &adj, int x, int y) {
	//write your code here
	int i, j,visited=1;
	IsVisit[x] = 1;
	for(i = 0; i<adj[x].size(); i++) {		
		if (adj[x][i] == y ) {
			return 1;
		}
	}
	for (i = 0; i < adj[x].size(); i++) {
		if (IsVisit[adj[x][i]] == 0) {
			if (reach(adj, adj[x][i], y))
				return 1;
		}
		IsVisit[adj[x][i]] = 1; 
	}
	return 0;
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
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, x - 1, y - 1);
}
