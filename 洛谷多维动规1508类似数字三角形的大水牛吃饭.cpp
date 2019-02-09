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

int eat[210][210], m, n;
int firway[3] = { -1, -1, -1 };
int secway[3] = { -1, 0, 1 };

int MaxThree(int a, int b, int c) {
	if (a >= b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

int main() {
	m = read();
	n = read();
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= n; ++k) {
			eat[i][k] = read();
		}
	}

	// 注意特判!
	if (n == 1) {
		int sum = 0;
		for (int i = 1; i <= m; ++i)
			sum += eat[i][1];
		printf("%d\n", sum);
	}

	else {
		for (int i = 2; i <= m; ++i) {
			eat[i][1] += eat[i - 1][1] > eat[i - 1][2] ? eat[i - 1][1] : eat[i - 1][2];
			eat[i][n] += eat[i - 1][n] > eat[i - 1][n - 1] ? eat[i - 1][n] : eat[i - 1][n - 1];
			for (int k = 2; k < n; ++k) {
				eat[i][k] += MaxThree(eat[i - 1][k - 1], eat[i - 1][k], eat[i - 1][k + 1]);
			}
		}


		printf("%d\n", MaxThree(eat[m][n / 2], eat[m][n / 2 + 1], eat[m][n / 2 + 2]));
	}

	return 0;
}

/*
n*m(n and m<=200)的矩型的巨型大餐桌, 所有的食物按其所能提供的能量打了分（有些是负的，因为吃了要拉肚子）

获得最大能量, 每组数据的出发点都是最后一行的中间位置的下方

[输入数据：]

第一行为m n.(n为奇数)，李大水牛一开始在最后一行的中间的下方

接下来为m*n的数字距阵.

共有m行,每行n个数字.数字间用空格隔开.代表该格子上的盘中的食物所能提供的能量.

数字全是整数.

输出最大能量

输入:
6 7
16 4 3 12 6 0 3
4 -5 6 7 0 0 2
6 0 -1 -2 3 6 8
5 3 4 0 0 -2 7
-1 7 4 0 7 -5 6
0 -1 3 4 12 4 2

输出:
41





*/
