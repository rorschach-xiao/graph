// Clustering.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using std::sort;
int uset[200] = { 0 };
struct edge {
	int v1;
	int v2;
	double weight;
	bool operator <(const edge &e)const {
		return weight < e.weight;
	}
};
bool comp(const edge&e1, const edge&e2) {
	return e1.weight < e2.weight;
}
void MakeSet(int n) {
	for (int i = 0; i < n; i++) {
		uset[i] = i;
	}
}
int Find(int x) {
	int root = x;
	while (uset[root] != root) {
		root = uset[root];
	}
	//压缩路径
	int i = x,j;
	while (uset[i] != i) {
		j = uset[i];
		uset[i] = root;
		i = j;
	}
	return root;
}
void Union(int x,int y) {
	int a = Find(x), b = Find(y);
	if (a != b) {
		uset[b] = a;
	}
}


double clustering(vector<int> x, vector<int> y, int k) {
	//write your code here
	vector<edge> E;
	vector<edge> X;
	edge temp;
	int n = x.size();
	MakeSet(n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp.v1 = i; temp.v2 = j;
			temp.weight = sqrt(pow((double)(x[i] - x[j]), 2) + pow((double)(y[i] - y[j]), 2));
			E.push_back(temp);
		}
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		if (Find(E[i].v1) != Find(E[i].v2)) {
			Union(E[i].v1, E[i].v2);
			X.push_back(E[i]);
		}
	}
	sort(X.begin(), X.end());  //从生成的MST中去除最长的k-1条边
	int n1 = X.size();         //k-1条边中最短的就是d
	return X[n1 - k+1].weight;  
}

int main() {
	size_t n;
	int k;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cin >> k;
	std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
