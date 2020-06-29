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

int n, m;
int arr[32];
int dp[20010];

int main() {
	in(n), in(m);

	Fee(i, 1, m) {
		in(arr[i]);
	}

	Fee(i, 1, m) {
		Ree(k, n, 0) {
			if (k >= arr[i])
				dp[k] = max(dp[k], dp[k - arr[i]] + arr[i]);
		}
	}

	cout << n - dp[n] << endl;

	return 0;
}