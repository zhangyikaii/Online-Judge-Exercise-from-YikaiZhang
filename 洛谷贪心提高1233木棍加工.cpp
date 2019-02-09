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

struct Data
{
	int a, b;
};

bool cmp(Data x, Data y) {
	return x.a > y.a;
}

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

int n, maxx = -1;
int dp[5010];
Data arr[5010];

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		arr[i].a = read();
		arr[i].b = read();
	}

	sort(arr + 1, arr + n + 1, cmp);

	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int k = 1; k < i; ++k) {
			if (arr[k].b < arr[i].b)
				dp[i] = max(dp[i], dp[k] + 1);
		}
		if (maxx < dp[i])
			maxx = dp[i];
	}

	printf("%d\n", maxx);


	return 0;
}

/*
第一根棍子的准备时间为1分钟；

如果刚处理完长度为L，宽度为W的棍子，那么如果下一个棍子长度为Li，宽度为Wi，并且满足L>＝Li，W>＝Wi，这个棍子就不需要准备时间，否则需要1分钟的准备时间；

计算处理完n根棍子所需要的最短准备时间。比如，你有5根棍子，长度和宽度分别为(4, 9)，(5, 2)，(2, 1)，(3, 5)，(1, 4)，最短准备时间为2（按(4, 9)、(3, 5)、(1, 4)、(5, 2)、(2, 1)的次序进行加工）。

输入格式：
第一行是一个整数n(n<＝5000)，第2行是2n个整数，分别是L1，W1，L2，w2，…，Ln，Wn。L和W的值均不超过10000，相邻两数之间用空格分开。

输出格式：
仅一行，一个整数，所需要的最短准备时间。

输入:
5
4 9 5 2 2 1 3 5 1 4


输出:
2


*/
