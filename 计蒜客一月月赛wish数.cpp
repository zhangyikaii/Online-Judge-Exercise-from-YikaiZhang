#include <iostream>
using namespace std;
#define MAX 105

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
	

	return 0;
}



/*
如果一个数大于等于 10 且任意连续两位都是质数，那么就称之为 Wish 数。当然，第一个 Wish 数是 11。 比如 97，111，131，119 都是 Wish 数，而 12，136 则不是。 问第 N 个 Wish 数是多少。
*/