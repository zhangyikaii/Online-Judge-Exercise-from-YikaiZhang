#include <iostream>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll pow1(ll a, ll b) {
	ll r = 1;
	while (b) {
		if (b & 1)
			r = r*a%mod;
		a = a*a%mod;
		b /= 2;
	}
	return r;
}
int main() {
	int n, m, k, a, b;
	scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
	ll p = 1LL * a * pow1(b, mod - 2) % mod;
	ll s = 1LL * (n + m) * pow1(n + m + 1, mod - 2) % mod;
	ll ans = 1LL * n*pow1(s, k) % mod + p*(s - pow1(s, k + 1)) % mod*pow1(1 - s, mod - 2) % mod;
	ans = ans%mod + mod;
	printf("%lld\n", ans%mod);
	return 0;
}