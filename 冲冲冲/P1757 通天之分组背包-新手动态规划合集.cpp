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
int sumGrp;
int wei[1100], val[1100], grp[1100];
int dp[1100];

int main() {
	in(m), in(n);

	Fee(i, 1, n) {
		in(wei[i]), in(val[i]), in(grp[i]);
		sumGrp = max(sumGrp, grp[i]);
	}

	Fee(i, 1, sumGrp) {
		// 遍历所有的组:
		Ree(k, m, 0) {
			Fee(j, 1, n) {
				if (grp[j] == i) {
					if (k >= wei[j])
						dp[k] = max(dp[k], dp[k - wei[j]] + val[j]);
				}
			}
		}
	}

	cout << dp[m] << endl;
	

	return 0;
}