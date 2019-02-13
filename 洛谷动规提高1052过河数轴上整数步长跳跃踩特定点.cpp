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

// 这题关键就在路径压缩

int f[10005], far[10005], a[10005], flag[10005], p, s, t, n;

int main()
{
	scanf("%d", &p);
	scanf("%d%d%d", &s, &t, &n);
	if (s == t) //特殊情况判断
	{
		int cont = 0, qaq;
		for (int i = 1; i <= n; ++i)scanf("%d", &qaq), cont += ((qaq%s) == 0);
		printf("%d\n", cont); return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); 
	
	a[0] = 0; f[0] = 0;

	far[n + 1] = min(p - a[n], 100); 
	p = 0; //计算终点与最后一个点的距离
	for (int i = 1; i <= n; i++)
		far[i] = min(a[i] - a[i - 1], 90), p += far[i], flag[p] = 1; // 缩短路径，存储缩短后的终点距离并标记石头位置
	p += far[n + 1];
	for (int i = 1; i <= p + 9; i++) {
		f[i] = INT_MAX - 1;
		for (int j = s; j <= t; j++)
		if (i >= j)
			f[i] = min(f[i], f[i - j] + flag[i]);
	}
	int minn = INT_MAX - 1;
	for (int i = p; i <= p + 9; i++) // 因为青蛙可以跳出边界且t<=10因此在终点后p~p+9中取最小值
		minn = min(minn, f[i]);
	printf("%d", minn);
}

/*
给定区间, 青蛙跳跃步长是这个区间里的整数, 给定数轴上的一些特定点, 求最少踩到多少这些特定点.

<h2>输入输出格式</h2>
<strong>输入格式：</strong><br>
<p><p>第一行有$1$个正整数$L(1 \le L \le 10^9)$，表示独木桥的长度。</p>
<p>第二行有$3$个正整数$S,T,M$，分别表示青蛙一次跳跃的最小距离，最大距离及桥上石子的个数，其中$1 \le S \le T \le 10$,$1 \le M \le 100$。</p>
<p>第三行有$M$个不同的正整数分别表示这$M$个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。所有相邻的整数之间用一个空格隔开。</p></p>
<strong>输出格式：</strong><br>
<p><p>一个整数，表示青蛙过河最少需要踩到的石子数。</p></p>

输入输出样例
输入样例#1：
10
2 3 5
2 3 5 6 7

输出样例#1：
2

*/