#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)
	typedef long long ll;
	int waysToChange(int n) {
		vector<int> dp(n + 1);
		int coins[5] = { 25, 10, 5, 1 };
		dp[0] = 1;
		For(i, 0, 4) {
			Fee(k, 0, n) {
				if (k >= coins[i]) {
					dp[k] = (dp[k] + dp[k - coins[i]]) % 1000000007;
				}
			}
		}
		return dp[n];
	}
};

int main() {
	Solution s;
	cout << s.waysToChange(10) << endl;

	return 0;
}