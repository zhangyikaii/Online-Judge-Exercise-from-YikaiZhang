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

int n, k;

// 数学类的/xk 发现了怎么做就很简单了/xk
int main() {
	n = read();
	k = read();

	printf("%d\n", n / k);


	return 0;
}

/*
1~n 取k个, 使这k个的最大公约数最大

输入格式：
两个空格分开的正整数n和k。（n>=k>=1）

输出格式：
一个整数，为最大的默契值。
*/
