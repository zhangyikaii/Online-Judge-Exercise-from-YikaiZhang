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

int m, n, ans;

// 背住这个求最大公因数的函数

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	cout << gcd(12, 15);
	cin >> n >> m;
	for (int i = 1; i <= sqrt(m * n); i++)
	{
		if ((n*m) % i == 0 && gcd(i, (n*m) / i) == n)  ans++;
	}
	cout << ans * 2;//最后乘以二是因为只遍历了一半
	return 0;
}

/*
P,Q是正整数

要求 P,Q 以 x_0 为最大公约数,以 y_0 为最小公倍数.

试求:满足条件的所有可能的2个正整数的个数.


输入:
3 60

输出:
4

解释:
1、3,60
2、15,12
3、12,15
4、60,3
*/