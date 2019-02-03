#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
using namespace std;
#define For(i, n, m) for(ll i = n;i < m; ++i)
#define ll long long

inline ll read() {
	char s;
	ll k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k * base;
}
int n, addNum;
int finger[10010], 

void dfs(int cur) {
	if (cur == n) {
		--addNum;
		return;
	}
	if (addNum == 0)
		return;
}


int main() {
	n = read(), addNum = read();
	
	return 0;
}

/*
例子说明:
输入的这个排列是第 i 个, 输出第 i + 3 个排列

输入:
5
3
1 2 3 4 5

输出:
1 2 4 5 3

*/