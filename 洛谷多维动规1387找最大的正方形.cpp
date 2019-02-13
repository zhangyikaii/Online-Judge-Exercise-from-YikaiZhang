#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define in(x) x = read()
inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}
int n, m, ans = 0;
int matrix[110][110], dp[110][110];

int MyMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	in(n);
	in(m);

	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= m; ++k) {
			in(matrix[i][k]);
			if (matrix[i][k] == 1) {
				dp[i][k] = MyMin(MyMin(dp[i][k - 1], dp[i - 1][k]), dp[i - 1][k - 1]) + 1;
			}
			if (ans < dp[i][k])
				ans = dp[i][k];
		}
	}

	printf("%d\n", ans);

	return 0;
}

/*

题目描述
帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的n × m的矩阵，矩阵中的每个元素a_{i,j}均为非负整数。游戏规则如下：

每次取数时须从每行各取走一个元素，共n个。经过m次后取完矩阵内所有元素；
每次取走的各个元素只能是该元素所在行的行首或行尾；
每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值 * 2^i，其中i表示第i次取数（从1开始编号）；
游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

样例输入:
4 4
0 0 0 1
1 1 1 1
0 1 1 1
1 1 1 1

输出:
3

*/