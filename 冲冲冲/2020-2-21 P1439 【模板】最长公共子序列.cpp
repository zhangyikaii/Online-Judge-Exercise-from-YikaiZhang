#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

// P1439 【模板】最长公共子序列
int n;
int arr[1010], brr[1010];
int dp[1010][1010];

int main() {
	// 5 
	// 3 2 1 4 5
	// 1 2 3 4 5

	// 3

	in(n);
	++n;
	For(i, 1, n) {
		in(arr[i]);
	}
	For(i, 1, n) {
		in(brr[i]);
	}

	For(i, 1, n) {
		For(j, 1, n) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (arr[i] == brr[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	printf("%d\n", dp[n - 1][n - 1]);

	return 0;
}