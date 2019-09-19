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

int n, a[110];
int f[110] = { 0 }, f1[110] = { 0 };
int maxx = -1;
// f[i] 表示到第 i 个时 最长上升子序列的长度

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}

	for (int i = 1; i <= n; ++i) {
		f[i] = 1;
		for (int k = 1; k < i; ++k) {
			if (a[k] < a[i])
				f[i] = max(f[i], f[k] + 1);
		}
	}

	// 最长下降子序列反向做.
	for (int i = n; i >= 1; --i) {
		f1[i] = 1;
		for (int k = n; k > i; --k) {
			if (a[k] < a[i])
				f1[i] = max(f1[i], f1[k] + 1);
		}
	}

	// 注意 i 要落到同一个, 然后 - 1.
	for (int i = 0; i <= n; ++i) {
		// 注意!!! 合唱队形需要算合成的中间的那一个, 然后再扣除
		// 根据就是 f[] 的定义: 以a[i]结尾的最长上升子序列!
		if (maxx < f[i] + f1[i] - 1)
			maxx = f[i] + f1[i] - 1;
	}

	/*for (int i = 1; i <= n; ++i) {
		cout << f[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; ++i) {
		cout << f1[i] << " ";
	}
	cout << endl;*/

	printf("%d\n", n - maxx);            // 这题好/xk 输出的是出队的人数!!! 看题目呀

	return 0;
}

/*
合唱队形就是先上升后下降的队形, 也可以是一直上升或者一直下降

求序列中最长的合唱队形

输入:
8
186 186 150 200 160 130 197 220

输出:
4

*/
