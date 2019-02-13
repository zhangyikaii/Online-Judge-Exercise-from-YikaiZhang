#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <queue>
#include <stack>
#define mpr make_pair

using namespace std;

typedef long long LL;

const int inf = 1 << 26;

// 首先最直接想到的思路是用f[i][j][k][l][0 / 1] k 和 l 分别表示走到 i，j 点时两个人的分数。0、1表示谁吸魔液。但是这样需要枚举起点，4维再加两维内存不够, 思路就是把当前信息都记录下来
// 结果需要两个人之间的差值, 所以开一个维度记录差值

// dp[i][j][h][l] 表示在点 (i,j)，差值为h，小A还是uim取液体的方案数(0-->小A 1-->uim) 

// dp[i][j][h][1] += (dp[i - 1][j][(h - a[i][j] + k) % k][0]); // uim取，差值变小, 都要加上 k 避免出现负数
// dp[i][j][h][1] += (dp[i][j - 1][(h - a[i][j] + k) % k][0];
// dp[i][j][h][0] += (dp[i - 1][j][(h + a[i][j]) % k][1]);
// dp[i][j][h][0] += (dp[i][j - 1][(h + a[i][j]) % k][1]);

// 初始化：dp[i][j][a[i][j]][0] = 1;     // 一开始小A可以从任意点开始 

int dp[805][805][20][2];
int n, m, k;
int a[805][805];

const int mod = (int)1e9 + 7;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	++k;   // k+1会变成0，k不变 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j][a[i][j] % k][0] = 1;
		}
	}
	int ans = 0;
	// 遍历顺序
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int h = 0; h <= k; h++) {
				dp[i][j][h][0] = (dp[i][j][h][0] + dp[i - 1][j][(h - a[i][j] + k) % k][1]) % mod;
				dp[i][j][h][0] = (dp[i][j][h][0] + dp[i][j - 1][(h - a[i][j] + k) % k][1]) % mod;
				dp[i][j][h][1] = (dp[i][j][h][1] + dp[i - 1][j][(h + a[i][j]) % k][0]) % mod;
				dp[i][j][h][1] = (dp[i][j][h][1] + dp[i][j - 1][(h + a[i][j]) % k][0]) % mod;
			}
		}
	}

	// 因为起终点任意，所以初始每个位置的f方案数都是1，最后计算总方案数也要累加每个位置的f[x][y][0][1], 累计从每个位置出发的答案
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			ans = (ans + dp[i][j][0][1]) % mod;
	}
	printf("%d\n", ans);

	return 0;
}
/*
题目描述
瞬间，地面上出现了一个n*m的巨幅矩阵，矩阵的每个格子上有一坨0~k不等量的魔液。怪物各给了小a和uim一个魔瓶，说道，你们可以从矩阵的任一个格子开始，每次向右或向下走一步，从任一个格子结束。开始时小a用魔瓶吸收地面上的魔液，下一步由uim吸收，如此交替下去，并且要求最后一步必须由uim吸收。魔瓶只有k的容量，也就是说，如果装了k+1那么魔瓶会被清空成零，如果装了k+2就只剩下1，依次类推。怪物还说道，最后谁的魔瓶装的魔液多，谁就能活下来。小a和uim感情深厚，情同手足，怎能忍心让小伙伴离自己而去呢？沉默片刻，小a灵机一动，如果他俩的魔瓶中魔液一样多，不就都能活下来了吗？小a和他的小伙伴都笑呆了！

现在他想知道他们都能活下来有多少种方法。

输入输出格式
输入格式：
第一行，三个空格隔开的整数n，m，k

接下来n行，m列，表示矩阵每一个的魔液量。同一行的数字用空格隔开。

输出格式：
一个整数，表示方法数。由于可能很大，输出对1 000 000 007取余后的结果。

输入输出样例
输入样例#1：
2 2 3
1 1
1 1
输出样例#1：
4
*/