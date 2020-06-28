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
#include <map>
#include <sstream>

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

ll quickmi(ll q, ll n, ll mod) {
	ll ans = 1;
	while (n != 0) {
		if ((n & 0x1) == 1) {
			ans = (ans * q) % mod;
		}

		q = (q * q) % mod;
		n >>= 1;
	}

	return ans % mod;
}

int main() {
	ll t;
	in(t);
	while (t--) {
		ll q, n, p;
		in(q);
		in(n);
		in(p);

		printf("%d\n", (quickmi(q - 1, p - 2, p) * (quickmi(q, n, p) - 1) % p) * q % p);
	}

	return 0;
}

