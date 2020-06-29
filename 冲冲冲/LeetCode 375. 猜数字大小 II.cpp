#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)
	typedef long long ll;

	ll dp[500][500];
	ll min(ll a, ll b) {
		return a < b ? a : b;
	}
	int dfs(int l, int r) {
		if (dp[l][r] != 0xfffff)
			return dp[l][r];
		if (l >= r)
			return 0;
		if (r - l == 1) {
			dp[l][r] = l;
			return l;
		}
		
		For(i, l + 1, r) {
			dp[l][r] = min(dp[l][r], i + max(dfs(l , i - 1), dfs(i + 1, r)));
			// cout << dp[l][r] << endl;
		}
		return dp[l][r];
	}
	int getMoneyAmount(int n) {
		For(i, 0, 500) {
			For(j, 0, 500) {
				dp[i][j] = 0xfffff;
			}
		}
		return dfs(1, n);
	}
};

int main() {
	Solution s;

	cout << s.getMoneyAmount(124) << endl;

	return 0;
}