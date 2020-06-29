#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n, x;
int win[1100], lose[1100], used[1100];
ll dp[1100];
int main() {
	in(n), in(x);

	Fee(i, 1, n) {
		in(lose[i]), in(win[i]), in(used[i]);
	}

	Fee(i, 1, n) {
		Ree(k, x, 0) {
			if (k >= used[i])
				dp[k] = max(dp[k] + lose[i], dp[k - used[i]] + win[i]);
			else
				dp[k] = dp[k] + lose[i];
		}
	}
	
	ll ans = dp[x] * 5;
	cout << ans << endl;

	return 0;
}