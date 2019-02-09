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

#define MAX 1000001


bool isPrime[MAX] = { 0 };
int prime[MAX] = { 0 }, sumPrime[MAX] = { 0 };
int n, m, a, b, curSum = 0;


// isPrime 下标是某个数 = true表示是素数 false表示不是
// prime 按顺序存素数

void init() {
	int cnt = 1;
	memset(isPrime, 1, sizeof(isPrime));			// 初始化认为所有数都为素数
	isPrime[0] = isPrime[1] = 0;					// 0和1不是素数
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i])
			prime[cnt++] = i;						// 保存素数i
		for (int j = 1; j < cnt && prime[j] * i < MAX; j++) {
			isPrime[prime[j] * i] = 0;				// 筛掉小于等于i的素数和i的积构成的合数 !
		}
	}

	for (int i = 2; i <= MAX; ++i) {
		if (isPrime[i] == 1) {
			++curSum;
		}
		sumPrime[i] = curSum;
	}
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

int main() {
	init();
	n = read();
	m = read();
	while (n--) {
		a = read();
		b = read();
		if (a < 1 || b > m) {
			printf("Crossing the line\n");
		}
		else {
			printf("%d\n", sumPrime[b] - sumPrime[a - 1]);
		}
	}


	return 0;
}

/*
区间质数个数

输入输出格式
输入格式：
一行两个整数 询问次数n，范围m

接下来n行，每行两个整数 l,r 表示区间

输出格式：
对于每次询问输出个数 t，如l或r∉[1,m]输出 Crossing the line

输入:
2 5
1 3
2 6

输出:
2
Crossing the line

*/
