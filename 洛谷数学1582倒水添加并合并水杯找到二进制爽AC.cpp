#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
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

// 妙在 杯子水变成 2 之后, 后面合并之后就都是 2 的幂次了, 去想二进制
// 样例的 1015808 是 11111000000000000000

// 计算十进制数转二进制之后有多少个 1
int popcnt(int u) {
	int ret = 0;
	while (u)
	{
		u = (u & (u - 1));    // 将 u 最右边的 1 清除
		ret++;
	}
	return ret;
}

int n, k, ans = 0;
// 不断加上 lowbit() 即可
int main() {
	scanf("%d%d", &n, &k);
	while (popcnt(n) > k) 
		ans += n & -n, n += n & -n;
	printf("%d\n", ans);

	return 0;
}
/*

一天，CC买了N个容量可以认为是无限大的瓶子，开始时每个瓶子里有1升水。接着~~CC发现瓶子实在太多了，于是他决定保留不超过K个瓶子。每次他选择两个当前含水量相同的瓶子，把一个瓶子的水全部倒进另一个里，然后把空瓶丢弃。(不能丢弃有水的瓶子)

显然在某些情况下CC无法达到目标，比如N=3,K=1。此时CC会重新买一些新的瓶子(新瓶子容量无限，开始时有1升水)，以到达目标。

现在CC想知道，最少需要买多少新瓶子才能达到目标呢？

输入:
3 1

输出:
1

输入:
13 2

输出:
3

输入:
1000000 5

输出:
15808


输入 N, K  输出需要添加的杯子
*/