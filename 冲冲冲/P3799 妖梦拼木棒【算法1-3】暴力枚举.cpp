#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n, maxArr;
int mp[5010];

ll mod = pow(10, 9) + 7;

ll C(ll x, ll k) {
	//求得从n个数中取出k个数的组合
	//此处k=1 / 2，用了特判写法。
	//k = 1 时，C(x, 1) = x;
	//k = 2 时，C(x, 2) = x * (x - 1) / 2;
	return (k == 1ll ? x : x * (x - 1ll) / 2ll) % mod;
}

int main() {
	freopen("P3799_1.in", "r", stdin);
	in(n);
	ll tmp;
	For(i, 0, n) {
		in(tmp);
		++mp[tmp];
		if (tmp > maxArr)
			maxArr = tmp;
	}

	ll sum = 0;
	Fee(i, 2, maxArr) {
		if (mp[i] < 2)
			continue;
		ll curSum = C(mp[i], 2);
		Fee(j, 1, i / 2) {
			if (j != i - j && mp[j] >= 1 && mp[i - j] >= 1) {
				curSum *= (mp[j] * mp[i - j]);
				curSum %= mod;
			}
			else if (j == i - j && mp[j] >= 2) {
				curSum *= C(mp[j], 2);
				curSum %= mod;
			}
		}
		sum += curSum;
		sum %= mod;
	}

	cout << sum << endl;
	return 0;
}