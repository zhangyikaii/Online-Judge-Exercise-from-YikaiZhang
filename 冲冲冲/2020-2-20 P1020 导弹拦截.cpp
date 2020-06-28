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

// 基础的来:
// 最长上升子序列:

// P1020 导弹拦截

int arr[100010];
int dp[100010], bdp[100010];

int main() {
	// 1 7 6 2 3 4
	int idx = 0, ansa = 1, ansb = 1;
	while (cin >> arr[++idx]) {	}

	For(i, 1, idx) {
		dp[i] = bdp[i] = 1;
		For(k, 1, i) {
			if (arr[k] < arr[i]) {
				dp[i] = max(dp[i], dp[k] + 1);
			}
			else {
				bdp[i] = max(bdp[i], bdp[k] + 1);
			}
		}
	}
	For(i, 1, idx) {
		ansa = max(dp[i], ansa);
		ansb = max(bdp[i], ansb);
	}
	cout << ansb << endl << ansa << endl;
	return 0;
}