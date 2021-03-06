// MST-Kruscal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>

using std::vector;
using std::priority_queue;
int uset[200] = { 0 };

struct edge {
	int v1;
	int v2;
	double weight;
	bool operator < (edge &a) const {
		return weight < a.weight;
	}
};
bool comp(const edge &e1, const edge &e2) { //重定义sort函数中的comp函数
	return e1.weight < e2.weight;
}
//定义查并集函数MakeSet、Find、Union
void MakeSet(int n) {
	for (int i = 0; i < n; i++) {
		uset[i] = i;
	}
}
int Find(int a) {
	int root = a;
	while (uset[root] != root)
		root = uset[root];
	//路径压缩
	int i = a, j;
	while (i != root) {
		j = uset[i];
		uset[i] = root;
		i = j;
	}
	return root;
}
void Union(int x, int y) {
	int a = Find(x), b = Find(y);
	if (a != b) {
		uset[b] = a;
	}
}

double minimum_distance(vector<int> x, vector<int> y) {
	double result = 0.;
	vector<edge> E;//E存放连接定点的所有边
	vector<edge> X; //X放置已加入最小生成树的边
	edge temp;
	int n = x.size();
	int k = 0;
	MakeSet(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp.v1 = i;
			temp.v2 = j;
			temp.weight = sqrt(pow((double)(x[i] - x[j]), 2) + pow((double)(y[i] - y[j]), 2));
			E.push_back(temp);
		}
	}
	sort(E.begin(), E.end());//对边按照权重从小到大进行排序
	for (int i = 0; i < E.size(); i++) {
		if (Find(E[i].v1) != Find(E[i].v2)) {
			X.push_back(E[i]);
			Union(E[i].v1, E[i].v2);
		}
	}
	for (int i = 0; i < X.size(); i++) {
		result += X[i].weight;
	}
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
