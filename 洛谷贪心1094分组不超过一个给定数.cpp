#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
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
	return k*base;
}

int a[30010], used[30010] = { false };

// 离散的分组 要变成连续的! 速度比较快, 不用每次都找一遍! 所以先排序先排序! 这也是贪心的习惯! 排序后再连续扫一遍过去处理
int main() {
	int w = read(), n = read(), maxIndext = -1, maxW = -1, res = 0;
	For(i, 0, n) {
		a[i] = read();
	}

	For(i, 0, n) {
		if (used[i] == false) {
			maxIndext = -1, maxW = -1;
			For(k, 0, n) {
				if (used[k] == false && i != k && a[i] + a[k] <= w && a[i] + a[k] >= maxW) {
					maxIndext = k;
					maxW = a[i] + a[k];
				}
			}
			used[i] = true;
			if (maxIndext != -1)
				used[maxIndext] = true;
			++res;
		}
	}

	cout << res << endl;
	return 0;
}

/*
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得 的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品， 并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。

找出所有分组方案中分组数最少的一种，输出最少的分组数目。

// 输入第一行是每组上限, 第二行是组数
输入:
100
9
90
20
20
30
50
60
70
80
90

输出:
6

*/