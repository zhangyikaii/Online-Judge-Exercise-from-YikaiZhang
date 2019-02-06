#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
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

// 二分的精华记在笔记本里

int a[100010], n, b;
int lef, rig, mid;

// 判断在 b 个瓶盖里面, 这 b 个里面距离最近的值是不是可以达到 dis
bool judge(int dis) {
	
}

int main() {
	n = read();
	b = read();

	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}

	sort(a + 1, a + n + 1);

	lef = a[2] - a[1];
	rig = a[n] - a[1];

	while (lef <= rig) {
		mid = (lef + rig) >> 1;

	}

	return 0;
}

/*
他在地上丢了A个瓶盖，为了简化问题，我们可以当作这A个瓶盖丢在一条直线上，现在他想从这些瓶盖里找出B个，使得距离最近的2个距离最大，他想知道，最大可以到多少呢？

输入输出格式
输入格式：
第一行，两个整数，A,B。（B<=A<=100000）

第二行，A个整数，分别为这A个瓶盖坐标。

输出格式：
仅一个整数，为所求答案。
*/
