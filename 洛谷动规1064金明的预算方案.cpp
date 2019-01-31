#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int MyMax(int a, int b) {
	return (a > b) ? a : b;
}

#define MAX 70


/*
注意搜索方式！很重要！

01背包的决策：

1.不选，然后去考虑下一个
2.选，背包容量减掉那个重量，总值加上那个价值。

这个题的决策是五个，分别是：

1.不选，然后去考虑下一个
2.选且只选这个主件
3.选这个主件，并且选附件1
4.选这个主件，并且选附件2
5.选这个主件，并且选附件1和附件2.
*/

int main() {
	int N, m;
	N = read();
	m = read();
	int v[MAX], p[MAX], q[MAX];
	int f[MAX][32010];				// 前 i 个物品 花费 j 元
	int major[MAX], sumMajor = 1;   // sumMajor 从1开始存 实际主件个数是 sumMajor - 1

	for (int i = 0; i < MAX; ++i) {
		for (int k = 0; k < 32010; ++k) {
			f[i][k] = 0;
		}
	}

	for (int i = 1; i <= m; ++i) {
		v[i] = read();
		p[i] = read();
		q[i] = read();
		if (q[i] == 0) {
			major[sumMajor++] = i;     // 记录主件序号
		}
	}

	// dp数组就是从最大的体积开始看看放不放这个物品
	// k 从 N 开始遍历，遍历的是背包可能的体积，也是之前可能的选择
	// 背住下面这个！
	// f[i][v] = max{ f[i - 1][v](第 i 种商品不选), f[i - 1][v - g[k].weight] + g[k].cost }
	// f 数组是花 v 元钱买 i 个主件商品, 所能得到的最大重要度与价格的乘积
	// 注意! v 是当前花了那么多钱, 是一个瞬时的值, 就是花 v 元钱 买 前 i 个主件商品的一种搭配方案 这样的结合意思
	int iMajor = 1;

	for (int i = 0; i <= N; ++i)
		f[0][i] = 0;

	// 相当于构造主件的背包  只是加一个附件的循环 把最优附件选择加上去了
	for (int i = major[iMajor]; iMajor < sumMajor; ++iMajor) {

		i = major[iMajor];       // i: 主件对应所有物品的序号, iMajor: 第几个主件

		// 对之前的主件考虑 就是之前 (iMajor - 1) 个主件的最优方案(包括已经选择了的他们的附件) k: 花费
		// 简单讲: 这里考虑 不选主件 & 选且只选这个主件
		for (int k = N; k >= 0; --k) {
			if (k >= v[i])
				f[iMajor][k] = max(f[iMajor - 1][k], f[iMajor - 1][k - v[i]] + v[i] * p[i]);  // AAAAA
			else
				f[iMajor][k] = f[iMajor - 1][k];
		}

		// k: 花费
		// 简单讲: 这里考虑 选主件且选附件
		for (int j = 1; j <= m; ++j) {
			// 判断：如果选了这个附件之后会更大
			if (q[j] == i) {
				for (int k = N; k >= v[i] + v[j]; --k)
					f[iMajor][k] = max(f[iMajor][k], f[iMajor][k - (v[i] + v[j])] + v[i] * p[i] + v[j] * p[j]);  // BBBBB
			}
		}
	}

	cout << f[sumMajor - 1][N] << endl;

	// 总结: 其实明确了怎么选之后, 就去跑for (int k = N; k >= v[i]... 这个循环(为遍历所有选法设限制)
	// 然后更新解 注意AAAAA 和 BBBBB 的不同, BBBBB 处在f[iMajor][k]基础上, 因为之前已经更新过一次了.
	// 记住dp数组是 当前已经花了那么多

	return 0;
}


/*
如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有0个、1个或2个附件。附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，分为5等：用整数1−5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是10元的整数倍）。他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。

设第j件物品的价格为v[] 重要度为w[], 共选中了k件物品，

请你帮助金明设计一个满足要求的购物单。

输入输出格式
输入格式：
第1行，为两个正整数，用一个空格隔开：

N m  
（其中N(<32000)表示总钱数，m(<60)为希望购买物品的个数。）

从第22行到第m+1行，第j行给出了编号为j−1的物品的基本数据，每行有3个非负整数

v p q
（其中v表示该物品的价格（v<10000），p表示该物品的重要度（1−5），q表示该物品是主件还是附件。如果q=0，表示该物品为主件，如果q>0，表示该物品为附件，q是所属主件的编号）   q是所属主件的编号!

输出格式：
一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000）。

输入:
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

输出:
2200
*/