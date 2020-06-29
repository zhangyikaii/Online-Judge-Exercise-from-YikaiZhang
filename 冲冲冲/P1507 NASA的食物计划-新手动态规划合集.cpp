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
int v, m;
int vol[60], qua[60], cal[60];
int dp[410][410];

int main() {
	in(v), in(m);
	in(n);

	Fee(i, 1, n) {
		in(vol[i]), in(qua[i]), in(cal[i]);
	}

	// 两个约束. 那就两层遍历;

	Fee(i, 1, n) {
		Ree(k, v, 0) {
			Ree(j, m, 0) {
				if (k >= vol[i] && j >= qua[i]) {
					dp[k][j] = max(dp[k - vol[i]][j - qua[i]] + cal[i], dp[k][j]);
				}
			}
		}
	}

	cout << dp[v][m] << endl;

	return 0;
}