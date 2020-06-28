#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <assert.h>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
ll MOD = 998244353;


class BinomialCoefficient {
private:
	vector<ll> factorial;
	vector<ll> factorial_inverse;
	ll n, mod;

public:
	BinomialCoefficient() {}
	BinomialCoefficient(ll _n, ll _mod) : n(_n), mod(_mod) {
		factorial = vector<ll>(n + 1, 1);
		factorial_inverse = vector<ll>(n + 1, 1);
		for (ll i = 1; i <= n; i++)
			factorial[i] = (long long)factorial[i - 1] * i % mod;
		for (ll i = 2; i <= n; i++)
			factorial_inverse[i] = mod - (long long)factorial_inverse[mod % i] * (mod / i) % mod;
		for (ll i = 1; i <= n; i++) {
			factorial_inverse[i] = (long long)factorial_inverse[i - 1] * factorial_inverse[i] % mod;
			assert((long long)factorial[i] * factorial_inverse[i] % mod == 1);
		}
	}

	ll operator ()(const ll n, const ll m) const {
		assert(n >= m && n >= 0 && m >= 0);
		return (long long)factorial[n] * factorial_inverse[m] % mod * factorial_inverse[n - m] % mod;
	}
} C(5000, MOD);

ll ff(ll a) {
	ll ret = 1;
	for (ll i = 1; i <= a; ++i) {
		ret = (ret * i) % MOD;
	}

	return ret;
}

ll inv(ll x) {
	ll b = MOD - 2, ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans * x) % MOD;
		}

		x = x * x % MOD;
		b >>= 1;
	}

	return ans;
}

int main() {
	ll n, m, res = 0;
	in(n), in(m);

	ll up = ff(n * m);
	ll nn = ff(n), mm = ff(m);

	ll t = (nn * mm) % MOD;

	res = up * inv(t) % MOD;
	
	printf("%lld\n", res);

	return 0;
}