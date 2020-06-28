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

int w, arr[110], n;
int dp[110][20010];

int main() {
	//in(w), in(n);
	//++n;
	//For(i, 1, n) {
	//	in(arr[i]);
	//}

	//For(i, 1, n) {
	//	For(k, 0, arr[i]) {
	//		dp[i][k] = dp[i - 1][k];
	//	}
	//	// 注意遍历的头尾是到哪儿呀!
	//	For(k, arr[i], w + 1) {
	//		dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - arr[i]] + arr[i]);
	//	}
	//	//for (int k = w; k >= arr[i]; --k) {
	//	//	dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - arr[i]] + arr[i]);
	//	//}
	//	//for (int k = arr[i] - 1; k >= 0; --k) {
	//	//	dp[i][k] = dp[i - 1][k];
	//	//}
	//}

	//printf("%d\n", w - dp[n - 1][w]);

	char a = 76;
	cout << a << endl;

	return 0;
}