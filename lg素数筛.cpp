#include <bits/stdc++.h>
using namespace std;

int isPrime[100010], prime[100010];
int cnt = 0;

void Init() {
	isPrime[0] = 1, isPrime[1] = 1;

	for (int i = 2; i < 100000; ++i) {
		// 注意, 就是在这里记录!
		if (isPrime[i] == 0)
			prime[cnt++] = i;
		for (int j = 0; j < cnt && prime[j] * i < 100000; ++j)
			isPrime[prime[j] * i] = 1;
	}
}

int main() {
	Init();

	int n;
	cin >> n;

	for (int i = 0; i < cnt; ++i) {
		for (int j = i; j < cnt; ++j) {
			if (isPrime[n - prime[i] - prime[j]] == 0) {
				cout << prime[i] << " " << prime[j] << " " << n - prime[i] - prime[j] << endl;
				return 0;
			}
		}
	}


	return 0;
}