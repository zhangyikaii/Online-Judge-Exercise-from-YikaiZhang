#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

#define MAXN 1000010

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

unsigned int f(std::string s, unsigned int base, unsigned int mod) {
	unsigned int rt = 0;
	for (auto i = 0; i < s.size(); i++)
		rt = ((unsigned long long)rt * base + s[i] - 'a') % mod;
	return rt;
}
vector<int> v;

string sss;

int main() {
	ll base, mod, k, tmp;
	in(base);
	in(mod);
	in(k);
	if (k == 0) {
		printf("a\n");
		return 0;
	}
	// k %= mod;

	for (; k > 0; k += mod) {
		ll tk = k;
		while (tk >= base) {
			tmp = tk % base;
			if (tmp > 25) {
				v.clear();
				break;
			}
			v.push_back(tmp);
			tk /= base;
		}
		if (!v.empty() && tk <= 25) {
			v.push_back(tk);
			break;
		}
	}

	for (ll i = v.size() - 1; i >= 0; --i) {
		printf("%c", 'a' + v[i]);
		sss += ('a' + v[i]);
	}

	printf("\n");
	return 0;
}