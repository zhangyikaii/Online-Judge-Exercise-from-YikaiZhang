#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>


#define MAX 110
using namespace std;
int n, m, a[MAX], f[MAX][10010];
int f1[10010] = { 0 };

/*
// 没有降维的
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	// 表示花费零元的方案 所有不买 肯定是一种（边界条件）
	for (int i = 0; i <= n; i++)				    // 注意这里要从0开始 
		f[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] += f[i - 1][j];					// #不买第 i 件菜品#（这里指的是当前已经花了 j 元 如果 j < a[i] 当然不可能是买了第 i 件菜品
			if (j >= a[i])
				f[i][j] += f[i - 1][j - a[i]];		// #买了第 i 件菜品# 也就是说 $f[i - 1][j - a[i]]$ 表示的方案：就是前 i 件菜品花了 j - a[i] 元，加上买的第 i 件 的这样的方案
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
*/

// 降维：
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	// 表示花费零元的方案 所有不买 肯定是一种（边界条件）
	f1[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; --j) {
			f1[j] += f1[j];					// # 不买第 i 件菜品#（这里指的是当前已经花了 j 元 如果 j < a[i] 当然不可能是买了第 i 件菜品
			if (j >= a[i])
				f1[j] += f1[j - a[i]];		// # 买了第 i 件菜品# 也就是说 $f[i - 1][j - a[i]]$ 表示的方案：就是前 i 件菜品花了 j - a[i] 元，加上买的第 i 件 的这样的方案
		}
	}
	cout << f1[m] << endl;
	return 0;
}














/*
总结：
dp[i][j]表示前i个菜品恰好花费j元的方案数 dp数组都是这样 前i个物品 花费j元 dp[i][j] 表示的就是答案对应的(方案数)了
注意这里和金明那题求最优权值和, 这里是方案数, 是一个加的关系.
*/

/*
uim口袋里只剩M元(M≤10000)。

餐馆虽低端，但是菜品种类不少，有MAX种(MAX≤100)，第i种卖a_i, 由于是很低端的餐馆，所以每种菜只有一份。

小A奉行“不把钱吃光不罢休”，所以他点单一定刚好吧uim身上所有钱花完。他想知道有多少种点菜方法。

由于小A肚子太饿，所以最多只能等待1秒。

输入输出格式
输入格式：
第一行是两个数字，表示MAX和M。

第二行起MAX个正数a_i（可以有相同的数字，每个数字均在1000以内）。

输出格式：
一个正整数，表示点菜方案数，保证答案的范围在int之内。
*/