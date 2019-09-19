#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <string.h>

#include <assert.h>

using namespace std;

#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

#define MOD 1000000007

#define SIGN(A) ((A > 0) ? 1 : -1) 

typedef long long ll;

#define in(x) x=read()

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
using namespace std;

class BinomialCoefficient {
private:
	vector<int> factorial;
	vector<int> factorial_inverse;
	int n, mod;

public:
	BinomialCoefficient() {}
	BinomialCoefficient(int _n, int _mod) : n(_n), mod(_mod) {
		factorial = vector<int>(n + 1, 1);
		factorial_inverse = vector<int>(n + 1, 1);
		for (int i = 1; i <= n; i++)
			factorial[i] = (long long)factorial[i - 1] * i % mod;
		for (int i = 2; i <= n; i++)
			factorial_inverse[i] = mod - (long long)factorial_inverse[mod % i] * (mod / i) % mod;
		for (int i = 1; i <= n; i++) {
			factorial_inverse[i] = (long long)factorial_inverse[i - 1] * factorial_inverse[i] % mod;
			assert((long long)factorial[i] * factorial_inverse[i] % mod == 1);
		}
	}

	int operator ()(const int n, const int m) const {
		assert(n >= m && n >= 0 && m >= 0);
		return (long long)factorial[n] * factorial_inverse[m] % mod * factorial_inverse[n - m] % mod;
	}
} C(2000000, MOD);


ll A, B, CC, D, AC, BD, ABCD;

ll poww(ll n) {
	ll res = 1;
	for (int i = 0; i < n; ++i) {
		res *= 10;
	}
	return res;
}

ll divideConquer(ll X, ll Y, ll n1, ll n2){
	ll sign = SIGN(X) * SIGN(Y);
	ll x = abs(X);
	ll y = abs(Y);
	if (x == 0 || y == 0){
		return 0;
	}
	else if (n1 == 1 || n2 == 1){
		return sign * x * y;
	}
	else{
		A = (ll)x / poww((ll)(n1 / 2));
		B = x - A * poww(n1 / 2);
		CC = (ll)y / poww((ll)(n2 / 2));
		D = y - CC * poww(n2 / 2);
		AC = divideConquer(A, CC, n1 / 2, n2 / 2) % MOD;
		BD = divideConquer(B, D, n1 / 2) % MOD;
		ABCD = divideConquer((A - B), (D - CC), n / 2) % MOD + AC + BD;
		return sign * ((AC * poww(n)) % MOD + (ABCD * poww((ll)(n / 2))) % MOD + BD);
	}
}

//int a[10000], b[10000], i, j, len, c[10000];
//ll GaoJing(char a1[], int an, char b1[], int bn) {
//	ll res = 0;
//	for (i = 1; i <= an; ++i)
//		a[i] = a1[an - i] - '0';
//	for (i = 1; i <= bn; ++i)
//		b[i] = b1[bn - i] - '0';
//	for (i = 1; i <= an; ++i) {
//		for (j = 1; j <= bn; ++j)
//			c[i + j - 1] += a[i] * b[j];
//	}
//
//	len = an + bn;
//	for (i = 1; i < len; ++i) {
//		if (c[i] > 9) {
//			c[i + 1] += c[i] / 10;
//			c[i] %= 10;
//		}
//	}
//	while (c[len] == 0 && len > 1)
//		len--;
//	
//	if (len < 18) {
//		for (i = len; i >= 1; --i)
//			res = res * 10 + c[i];
//		return res % MOD;
//	}
//	else {
//		for (int i = 1; i <= len; ++i) {
//			if (i == 18)
//				res %= MOD;
//			res = (res * 10 + c[i]);
//		}
//		return res % MOD;
//	}
//	
//	return 0;
//}

int main() {
	cout << divideConquer((ll)124342, (ll)235987, (ll)6) << endl;
	ll T = 0;
	in(T);
	while (T--) {
		ll a = 0, b = 0, x = 0, ans = 0;
		in(a);
		in(b);
		x = a > b ? b : a;
		for (ll i = 0; i <= x; ++i) {
			int at = C(a, i), bt = C(b, i);
			if ((int)log10(at) < 9 && (int)log10(bt) < 9)
				ans = (ans + (ll)at * (ll)bt) % MOD;
			else {
				//char act[100] = "", bct[100] = "";
				//sprintf(act, "%lld", at), sprintf(bct, "%lld", bt);
				//ans = (ans + GaoJing(act, 1 + (int)log10(at), bct, 1 + (int)log10(bt))) % MOD;
				
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}