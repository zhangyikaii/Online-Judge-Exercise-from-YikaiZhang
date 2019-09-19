#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

ll isPrime[100010], prime[100010];

int cnt = 0;

vector<pair<ll, ll> > vec;

void Init() {
	isPrime[0] = isPrime[1] = 1;
	for (int i = 2; i < 100010; ++i) {
		if (isPrime[i] == 0)
			prime[++cnt] = i;
		for (int k = 1; k <= cnt && prime[k] * i < 100010; ++k) {
			isPrime[prime[k] * i] = 1;
		}
	}
}

int main() {
	cin >> n;

	ll resn = n;

	// 特判!!!
	if (n == 1 || n == 0) {
		printf("%lld=%lld\n", n, n);
		return 0;
	}

	Init();

	for (int i = 1; n != 1 && i <= cnt; ++i) {
		int pos = -1;
		while (n != 1 && n % prime[i] == 0) {
			if (pos == -1) {
				vec.push_back(make_pair(prime[i], 1));
				pos = vec.size() - 1;
			}
			else {
				vec[pos].second++;
			}
			n /= prime[i];
		}
	}

	printf("%lld=", resn);

	if (vec.size() != 0) {
		for (int i = 0; i < vec.size(); ++i) {
			if (i != 0)
				printf("*");
			if (vec[i].second == 1) {
				printf("%lld", vec[i].first);
			}
			else {
				printf("%lld^%lld", vec[i].first, vec[i].second);
			}
		}
		if (n != 1)
			printf("*%lld", n);				// 碰到大素数的处理方法!!!
	}
	// 本身就是大素数的处理!
	else {
		printf("%lld", resn);
	}

	printf("\n");

	return 0;
}