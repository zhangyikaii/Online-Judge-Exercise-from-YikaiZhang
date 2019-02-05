#include <iostream>
using namespace std;
#define MAX 105

bool isPrime[MAX] = { 0 };
int prime[MAX] = { 0 };



// isPrime 下标是某个数 = true表示是素数 false表示不是
// prime 按顺序存素数


void init() {
	int cnt = 1;
	memset(isPrime, 1, sizeof(isPrime));			// 初始化认为所有数都为素数llllllllllllllllllllllll
	isPrime[0] = isPrime[1] = 0;					// 0和1不是素数
	for (long long i = 2; i <= MAX; i++) {
		if (isPrime[i])
			prime[cnt++] = i;						// 保存素数i
		for (long long j = 1; j<cnt && prime[j] * i < MAX; j++) {
			isPrime[prime[j] * i] = 0;				// 筛掉小于等于i的素数和i的积构成的合数
		}
	}
}

int main() {
	init();

	return 0;
}