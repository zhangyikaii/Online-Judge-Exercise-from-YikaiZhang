//////// 这种题目还是老老实实dfs + 剪枝吧, dp的边界很迷
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
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

/*
// 动规解法!!!!!!
将n个小球放到k个盒子中的情况总数 =

a. 至少有一个盒子只有一个小球的情况数 + b. 没有一个盒子只有一个小球的情况数

对于
a. 因为盒子不加区分，那么 a 的情况数与 "将n-1个小球放到k-1个盒子中" 的情况数一样

b.没有一个盒子只有一个小球，那么把每个盒子中拿出来一个小球 每个盒子中拿出来一个小球!!! 高中的思路!!!，对应的是 "把(n-k)个小球放到k个盒子中的情况数"

写出状态转移方程:
f[i][j] 就是把 i 个 小球放在 j 个盒子里面的方案数
f[i][j] = f[i - 1][j - 1] + f[i - j][j];           j 是盒子总数
*/

int n, k;

int main() {
	int f[210][7];
	n = read(), k = read();
	// 边界真的真的太重要了/xk /xk
	// 下面的for处理边界是错的!!!
	/*for (int i = 0; i <= n; ++i) {
		for (int k = 0; k <= i; ++k) {
			if (k != i)
				f[i][k] = 0;
			else
				f[i][k] = 1;
		}
	}*/
	for (int i = 0; i <= n; ++i) {
		f[i][1] = 1;
		f[i][0] = 1;
	}
	for (int i = 0; i <= k; ++i) {
		f[0][i] = 0;
		f[1][i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (i < j) {
				// cout << "1: " << f[i - 1][j - 1] << endl;
				f[i][j] = f[i - 1][j - 1];
			}
			else {
				// cout << "2: " << f[i - 1][j - 1] << " " << f[i - j][j] << endl;
				f[i][j] = f[i - 1][j - 1] + f[i - j][j];
			}
		}
	}

	cout << f[n][k] << endl;

	return 0;
}


/*
// dfs解法!!!!!!!!!!
int n, k;
int ans = 0;

// dfs 处理这样在不同位置尝试或者不尝试的问题:
// 设置一个base, 让数在每次递归之后按照位都是不断增长
// 注意因为每一位都是不断增长的, 注意可以有预留接下来数字的思路去放东西, 只有这样剪枝回过
void dfs(int base, int curSum, int level) {
	if (level == k && curSum == n) {
		++ans;
		return;
	}

	if (level < k) {
		// curSum + i * (k - level) <= n 这是在保证后面都是上升的剪枝
		for (int i = base; curSum + i * (k - level) <= n; ++i) {
			dfs(i, curSum + i, level + 1);
		}
	}
}

int main() {
	n = read(), k = read();
	dfs(1, 0, 0);

	printf("%d\n", ans);

	return 0;
}

*/

/*

将n个小球放到k个盒子中，小球之间与盒子之间没有区别，并且最后的结果不允许空盒

输入:
7 3

输出:
4


4 种分组解释:
1 1 5
1 2 4
1 3 3
2 2 3
*/
