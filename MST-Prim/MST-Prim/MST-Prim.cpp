// MST-Kruscal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using std::vector;
using std::priority_queue;
double inf = std::numeric_limits<double>::infinity();
int IsVisit[200] = { 0 };
struct node {
	int num;
	double cost;
	node *pre = NULL;
	bool operator < (const node &a) const {
		return cost > a.cost;
	}
};



double minimum_distance(vector<int> x, vector<int> y) {
	double result = 0.;
	int n = x.size();
	double E[200][200];
	priority_queue<node> Q;
	node u;
	vector<node> cost(n);
	for (int i = 0; i < n; i++) {
		cost[i].cost = inf;
		cost[i].num = i;
	}
	for(int i = 0; i < n; i++) {
		E[i][i] = 0;
		for (int j = i + 1; j < n; j++) {
			E[i][j] = sqrt(pow((double)(x[i] - x[j]), 2) + pow((double)(y[i] - y[j]), 2));
			E[j][i] = sqrt(pow((double)(x[i] - x[j]), 2) + pow((double)(y[i] - y[j]), 2));
		}
	}
	cost[0].cost = 0;
    Q.push(cost[0]);
	while (!Q.empty()) {
		u = Q.top();
		Q.pop();
		IsVisit[u.num] = 1;
		for (int i = 0; i < n; i++) {
			if (i == u.num)
				continue;
			if (IsVisit[i]==0 && cost[i].cost > E[u.num][i]) {
				cost[i].cost = E[u.num][i];
				cost[i].pre = &u;
				Q.push(cost[i]);
			}
		}
	}
	for (int i = 0; i < n; i++)
		result += cost[i].cost;
	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
