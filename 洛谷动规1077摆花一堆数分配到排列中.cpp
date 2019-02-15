#include<cstdio>
#include<cstring>
#define mod 1000007
int max(int x, int y){ return x>y ? x : y; }
int f[101][101];						// f[i][j]指摆第 i 个花后总共摆 j 盆的最优解
int main()
{
	int n, m, t;
	scanf("%d%d", &n, &m);
	memset(f, 0, sizeof(f));
	for (int i = 0; i <= n; i++)
		f[i][0] = 1;
	for (int i = 1; i <= n; i++)				// 枚举到第i盆花
	{
		scanf("%d", &t);
		for (int j = 0; j <= t; j++) {			// 第i盆花装j盆
			for (int k = 0; k <= m - j; k++) {	// 从已经装k盆转移过来
				if (j == 0 && k == 0)
					continue;
				f[i][j + k] += f[i - 1][k];
				f[i][j + k] %= mod;
			}
		}
	}
	printf("%d\n", f[n][m] % mod);
	return 0;
}
/*
题目描述
小明的花店新开张，为了吸引顾客，他想在花店的门口摆上一排花，共mm盆。通过调查顾客的喜好，小明列出了顾客最喜欢的nn种花，从11到nn标号。为了在门口展出更多种花，规定第ii种花不能超过a_i盆，摆花时同一种花放在一起，且不同种类的花需按标号的从小到大的顺序依次摆列。

试编程计算，一共有多少种不同的摆花方案。


输出格式：
一个整数，表示有多少种方案。注意：因为方案数可能很多，请输出方案数对10000071000007取模的结果。

输入输出样例
输入样例#1：
2 4
3 2
输出样例#1：
2

*/