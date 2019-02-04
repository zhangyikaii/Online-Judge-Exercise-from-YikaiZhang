#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
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


int main() {
	int n = read(), ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += n / i;
	cout << ans << endl;
	// 思路: 1-n的因子个数，可以看成共含有2因子的数的个数+含有3因子的数的个数……+含有n因子的数的个数, 例如在1~n中含有“2”这个因子的数有n / 2个，3有n / 3个，以此类推，公式就出来了
	return 0;
}

/*
f(n)表示n的约数个数，现在给出n，要求求出f(1)到f(n)的总和。

12 的 约数有: 1、2、3、4、6、12  => f(12) = 6;

输入:
3

输出:
5
*/