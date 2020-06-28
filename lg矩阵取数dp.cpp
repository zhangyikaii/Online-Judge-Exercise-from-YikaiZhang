#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <assert.h>
#include <queue>

/*


*/

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)
	
typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m, k;

int arr[805][805];
int dp[805][805][20][2];
ll mod = 1000000007;
// dp[i][j][h][l] 表示在点 (i,j)，差值为h，小A还是uim取液体的方案数(0-->小A 1-->uim) 
// dp[i][j][h][1]+=(dp[i-1][j][(h-arr[i][j]+k)%k][0]) // uim取，差值就变小了
// dp[i][j][h][1]+=(dp[i][j-1][(h-arr[i][j]+k)%k][0])
// dp[i][j][h][0]+=(dp[i-1][j][(h+arr[i][j])%k][1]) // 小A取
// dp[i][j][h][0]+=(dp[i][j-1][(h+arr[i][j])%k][1]) 

// zhuyi 注意一下初始化的含义.
// 初始化：dp[i][j][arr[i][j]][0]=1;      // 一开始小A可以从任意点开始 


// dp 的 有点像把我们需要的信息都记录下来, 当然这些是可以推的.

int main() {
	ios::sync_with_stdio(false);
	in(n);
	in(m);
	in(k);

	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			in(arr[i][j]);
			dp[i][j][arr[i][j] % k][0] = 1;
		}
	}

	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			FOR(h, 0, k + 1) {
				dp[i][j][h][0] = (dp[i][j][h][0] + dp[i - 1][j][(h - arr[i][j] + k) % k][1]) % mod;
				dp[i][j][h][0] = (dp[i][j][h][0] + dp[i][j - 1][(h - arr[i][j] + k) % k][1]) % mod;
				dp[i][j][h][1] = (dp[i][j][h][1] + dp[i - 1][j][(h + arr[i][j]) % k][0]) % mod;
				dp[i][j][h][1] = (dp[i][j][h][1] + dp[i][j - 1][(h + arr[i][j]) % k][0]) % mod;
			}
		}
	}

	ll res = 0;
	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			res = (res + (ll)dp[i][j][0][1]) % mod;
		}
	}

	printf("%lld\n", res);


	

	return 0;
}
