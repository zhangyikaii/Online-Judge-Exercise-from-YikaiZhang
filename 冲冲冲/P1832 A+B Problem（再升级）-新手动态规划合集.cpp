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

// 筛法素数复习:
bool isNotPrime[10010];
void initPrime() {
	isNotPrime[0] = 1, isNotPrime[1] = 1;
	For(i, 2, 10010) {
		if (isNotPrime[i] == 0) {
			// 如果这个数是素数, 那么可以开始筛了:
			// i 的倍数都不是素数.
			for (int j = 2; i * j < 10010; ++j) {
				isNotPrime[i * j] = 1;
			}
		}
	}
}

int n;
ll dp[1010];
int main() {
	initPrime();
	
	cin >> n; // 输入
	// 完全背包: 每个素数都有无穷多个可以取.
	dp[0] = 1; // 边界值：当取数和为0时值为1
	Fee(i, 2, n) {
		// 每个素数考虑取或不取:
		if (isNotPrime[i] == 0) {
			Fee(j, i, n) {
				// 注意这里是方案数, 所以是 +=
				dp[j] += dp[j - i];
			}
		}
	}
	cout << dp[n] << endl;

	return 0;
}