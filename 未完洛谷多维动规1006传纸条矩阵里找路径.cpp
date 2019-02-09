#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

inline int read() {
	char s;
	int k = 0, base = 1;
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

int mapp[60][60], m, n;
int firway[3] = { -1, -1, -1 };
int secway[3] = { -1, 0, 1 };

int main() {
	m = read();
	n = read();
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= n; ++k) {
			mapp[i][k] = read();
		}
	}


	return 0;
}

/*
小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。一次素质拓展活动中，班上同学安排做成一个m行n列的矩阵，而小渊和小轩被安排在矩阵对角线的两端

即找到来回两条传递路径，使得这2条路径上同学的好心程度之和最大。现在，请你帮助小渊和小轩找到这样的2条路径。

输入:
3 3
0 3 9
2 8 5
5 7 0


输出:
34
*/