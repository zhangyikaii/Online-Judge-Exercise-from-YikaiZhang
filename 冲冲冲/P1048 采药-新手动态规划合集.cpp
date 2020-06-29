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

int t, m;
int arr[110], val[110];
int dp[1100];

int main() {
	in(t), in(m);

	Fee(i, 1, m) {
		in(arr[i]), in(val[i]);
	}

	Fee(i, 1, m) {
		Ree(k, t, 0) {
			if (k >= arr[i])
				dp[k] = max(dp[k], dp[k - arr[i]] + val[i]);
		}
	}

	cout << dp[t] << endl;

	return 0;
}