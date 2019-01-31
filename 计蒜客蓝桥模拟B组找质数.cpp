#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

#define For(i, n, m) for(int i = n;i < m; ++i)
inline int read()
{
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-'&&s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if (x / 10)write(x / 10);
		putchar(x % 10 + '0');
	}
}

#define MAX 1000005

bool isPrime[MAX] = { 0 };
int prime[MAX] = { 0 };

// isPrime 下标是某个数 = true表示是素数 false表示不是
// prime 按顺序存素数

void init() {
	int cnt = 1;
	memset(isPrime, 1, sizeof(isPrime));			// 初始化认为所有数都为素数
	isPrime[0] = isPrime[1] = 0;					// 0和1不是素数
	for (long long i = 2; i <= MAX; i++) {
		if (isPrime[i])
			prime[cnt++] = i;						// 保存素数i
		for (long long j = 1; j<cnt && prime[j] * i < MAX; j++) {
			isPrime[prime[j] * i] = 0;				// 筛掉小于等于i的素数和i的积构成的合数 !
		}
	}
}


int main() {
	init();
	int n = read(), a;
	For(i, 0, n) {
		a = read();
		if (isPrime[a - 2] == true) {
			printf("%d %d\n", 2, a - 2);
		}
		else {
			for (int i = 3; i < a; i += 2) {
				if (isPrime[i] == true && isPrime[a - i] == true) {
					printf("%d %d\n", i, a - i);
					break;
				}
			}
		}
	}



	return 0;
}

