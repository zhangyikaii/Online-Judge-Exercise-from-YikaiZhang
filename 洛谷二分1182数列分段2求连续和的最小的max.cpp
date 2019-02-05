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

struct Pair {
	int first, second;
	Pair() { }
	Pair(int a, int b) : first(a), second(b) { }
};

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

// 二分思想: 给一个大的范围, 在这个大的范围里面找答案, 二分找
// 这里大的范围就是 数列里面最大的数 ~ 整个数列的和

int n, m, maxx = -1, sum;
int arr[100010];

// 注意这个区间求和的函数要怎么写!
bool greedyFind(int divid, int maxSum) {
	int curSum = 0;
	for (int i = 1; i <= n; ++i) {
		if (curSum + arr[i] <= maxSum) 
	}
}

int main() {
	n = read(), m = read();

	for (int i = 1; i <= n; ++i) {
		arr[i] = read();
		sum += arr[i];
		if (maxx < arr[i])
			maxx = arr[i];
	}



	return 0;
}

/*

要求每段连续，且每段和的最大值最小。

例如一数列4 2 4 5 1要分成33段

将其如下分段：

[4 2][4 5][1]

输入:
5 3
4 2 4 5 1

输出:
6
*/
