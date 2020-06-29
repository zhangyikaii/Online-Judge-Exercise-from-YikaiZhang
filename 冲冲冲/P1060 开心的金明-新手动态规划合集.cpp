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

#define MAX 50000

// 动规注意各个下标表示的是什么
// dp数组不要忘了初始化为 0

int MyMax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, m;
	scanf("%d%d", &N, &m);
	int v[50], w[50];
	int dp[MAX] = { 0 };
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &v[i], &w[i]);
	}

	// 状态转移方程： f[i][v] = max{f[i-1][v](第 i 种商品不选) , f[i-1][v-g[k].weight] + g[k].cost}
	// dp[i] 就是用掉了i的体积 可以达到的最大值
	// 遍历每一个物品 对这个物品来说：dp数组就是从最大的体积开始看看放不放这个物品
	for (int i = 1; i <= m; ++i) {
		for (int k = N; k >= v[i]; --k) {
			dp[k] = MyMax(dp[k], dp[k - v[i]] + w[i] * v[i]);    // 是看这个物品放不放 所以下标是i！
		}
	}

	cout << dp[N] << endl;


	return 0;
}
