#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
// 注意这种类似动规的 用一个f[]记录的 dfs记忆化搜索!!!
using namespace std;
int n, m, t;
struct Data {
	int tim, mon;
} a[205];

int f[205][205][205];

int MyMax(int a, int b) {
	return a > b ? a : b;
}

// f[i][j][k] 为 前 i 个 金钱限制为 j, 时间限制为 k 下的物品最大值.

int main() {
	for (int i = 0; i <= 200; ++i) {
		for (int j = 0; j <= 200; ++j) {
			for (int k = 0; k <= 200; ++k)
				f[i][j][k] = 0;
		}
	}
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].tim, &a[i].mon);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= t; ++k) {
				// 很基本的01背包了, 就是加了一个维度
				if (a[i].mon <= j && a[i].tim <= k) {
					f[i][j][k] = MyMax(f[i - 1][j - a[i].mon][k - a[i].tim] + 1, f[i - 1][j][k]);
				}
				else
					f[i][j][k] = f[i - 1][j][k];
			}
		}
	}

	printf("%d\n", f[n][m][t]);

	return 0;
}


/*

这题就是 01 背包里面, 重量变成两个参量: 时间 + 金钱, 而01背包里的权值和, 变成都是1的(最大物品个数) 而已.

Kkksc03的时间和金钱是有限的，所以他很难满足所有同学的愿望。所以他想知道在自己的能力范围内，最多可以完成多少同学的愿望？

输入输出格式
输入格式：
第一行,n M T，表示一共有n(n<=100)个愿望，kkksc03 的手上还剩M(M<=200)元，他的暑假有T(T<=200)分钟时间。

第2~n+1行 mi,ti 表示第i个愿望所需要的金钱和时间。

输出格式：
一行，一个数，表示kkksc03最多可以实现愿望的个数。

输入输出样例
输入样例#1：
6 10 10
1 1
2 3
3 2
2 5
5 2
4 3
输出样例#1：
4

*/