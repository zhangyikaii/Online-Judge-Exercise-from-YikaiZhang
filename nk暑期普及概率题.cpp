// 下面是答案的概率dp解法, 真的精妙看不太懂.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double dp[2][5010];

void solve() {
	int n, a, b, m;
	scanf("%d %d %d %d", &n, &a, &b, &m);
	assert(a + b == n);
	if (n == 1) {
		if ((a + m) % 2 == 1) printf("1\n");
		else printf("0\n");
		return;
	}
	memset(dp, 0, sizeof(dp));
	dp[0][a] = 1;
	int tmp = 0;
	for (int i = 0; i < m; i++) {
		memset(dp[!tmp], 0, sizeof(dp[!tmp]));
		dp[!tmp][1] += dp[tmp][0];
		for (int j = 1; j < n; j++) {
			dp[!tmp][j - 1] += dp[tmp][j] * j / n;
			dp[!tmp][j + 1] += dp[tmp][j] * (n - j) / n;
		}
		dp[!tmp][n - 1] += dp[tmp][n];
		tmp = !tmp;
	}
	double ans = 0;
	for (int i = 0; i <= n; i++) ans += dp[tmp][i] * i;
	printf("%.7f\n", ans);
}

int main() {
	solve();
	return 0;
}

/*

这和之前做过的概率题解法很像很像.


链接：https://ac.nowcoder.com/acm/contest/926/C
来源：牛客网

题目描述
初始时有\ n n枚硬币，\ a a枚正面朝上，\ b b枚反面朝上。
每次操作完全随机地选择一枚硬币并翻转之，求进行\ m m次操作后正面朝上的硬币数量的数学期望\ ξ ξ。
请注意，本题的内存限制为32.000MB。
输入描述:
一行四个整数\ n,a,b,m n,a,b,m。

输出描述:
一行一个实数\ ξ ξ。--进行\ m m次操作后正面朝上的硬币数量的数学期望。当且仅当你的答案的绝对误差不超过10^{-6}10
−6
 的情况下会被认为正确
示例1
输入
复制
1 1 0 1
输出
复制
0
示例2
输入
复制
4 3 1 1
输出
复制
2.5


*/

// 找到递推公式之后的答案:

/*
#include <cstdio>

using namespace std;

double n, a, b, m;

int main()
{
	scanf("%lf%lf%lf%lf", &n, &a, &b, &m);
	for (int i = 1; i <= m; i++)
		a += (n - 2 * a) / n;
	printf("%.8lf\n", a);

	return 0;
}

*/
