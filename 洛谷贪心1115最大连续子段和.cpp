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

int n, a[200010];
int curSum = -1, maxx = -1;

// dp[i] 表示
int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}

	for (int i = 1; i <= n; ++i) {
		if (a[i] <= 0 && curSum == -1) {
			continue;
		}
		else if (a[i] > 0 && curSum == -1) {
			curSum = a[i];
		}
		else if (curSum != -1 && curSum + a[i] <= 0) {
			if (maxx < curSum)
				maxx = curSum;
			curSum = -1;
		}
		else if (curSum != -1 && curSum + a[i] > 0) {
			curSum += a[i];
			if (maxx < curSum)
				maxx = curSum;
		}
	}

	if (maxx == -1) {
		maxx = -999999;
		for (int i = 1; i <= n; ++i) {
			if (maxx < a[i])
				maxx = a[i];
		}
	}

	cout << maxx << endl;

	return 0;
}

/*
给出一段序列，选出其中连续且非空的一段使得这段和最大。

输入:
7
2 -4 3 -1 2 -4 3

输出:
4
*/
