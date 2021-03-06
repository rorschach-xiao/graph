// parentheses.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int main() {
	char s[50];
	vector<char> stack;
	cin >> s;
	for (int i = 0; i<strlen(s); i++) {
		if (s[i] == '(') {
			stack.push_back(s[i]);
		}
		else if (s[i] == ')') {
			if (!stack.empty()&&stack.back() == '(')
				stack.pop_back();
			else
				stack.push_back(s[i]);
		}
	}
	cout << stack.size();
	return 0;
}