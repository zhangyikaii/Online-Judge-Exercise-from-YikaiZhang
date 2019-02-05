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

// 注意 -1 % 5 = -1

// 还是要dp啊啊啊啊阿
// 方案数, 这里是给定情况的存在数问题, 还是比较好写边界条件的
/*
编号从 0 开始存, 一直存到 n - 1;
f[i][j] 表示传球次数 j , 传到编号为 i 的人的手里的时候;
f[i][j] = 她的左右两边传过来的方案总和 = f[(i + n - 1) % n][j - 1] + f[(i + 1) % n][j - 1];

注意边界条件!!!!!
*/
int n, m;

int main() {
	int f[50][50];
	n = read(), m = read();

	// 边界条件: 主要处理传了 0 次 和 传了 1 次
	f[0][1] = 0;
	f[1][1] = 1; 
	f[n - 1][1] = 1;

	for (int i = 2; i < n - 1; ++i)
		f[i][1] = 0;

	// 传了 0 次要怎么处理??? 按照实际情况!!!
	f[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		f[i][0] = 0;
	}

	// 如何更新??? 看状态转移方程, 发现 都是 j - 1 说明要从j的那列向前推进
	for (int j = 2; j <= m; ++j) {
		for (int i = 0; i < n; ++i) {
			f[i][j] = f[(i + n - 1) % n][j - 1] + f[(i + 1) % n][j - 1];
		}
	}

	cout << f[0][m] << endl;


	return 0;
}

// dfs又不剪枝简直大爆炸!
/*
int n, m, ans = 0;

void dfs(int cur, int level) {
	if (level == m && cur == 1) {
		++ans;
	}

	else if (level < m) {
		dfs((cur + 1) % m + 1, level + 1);
		dfs((cur - 1) % m + 1, level + 1);		
	}
}


int main() {
	n = read(), m = read();
	dfs(1, 0);

	cout << ans << endl;

	return 0;
}

*/

/*

每个同学可以把球传给自己左右的两个同学中的一个（左右任意） 注意左右都可以
n 个同学, 传了 m 次

求有几种传球方法:

输出:
3 3

输出:
2

解释:
1->2->3->1

1->3->2->1

*/
