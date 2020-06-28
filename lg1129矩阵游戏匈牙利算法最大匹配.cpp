
// 下面是答案, 注意如何转化成匹配问题.

#include<cstdio>
#include<cstring>
using namespace std;
const int maxN = 500;
int n, ans, t;

// 有一个match数组.
int matched[maxN + 1];

bool G[maxN + 1][maxN + 1], vis[maxN + 1];
// A 在左边, B 在右边, 从A往B连线(匹配)

// 为 A[x] 找哪个 B[i] 是它的匹配.
bool dfs(int x) {
	// A 去匹配(往B方向连线) B
	// 扫描对面每一个 B:
	for (int i = 1; i <= n; i++) {
		// 可能可以.
		if (G[x][i] && !vis[i]) {
			vis[i] = true;
			// 没有匹配过或者可以腾出位置来.
			if (!matched[i] || dfs(matched[i])) {
				matched[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(matched, 0, sizeof(matched));
		memset(G, false, sizeof(G));
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) scanf("%d", &G[i][j]);
		for (int i = 1; i <= n; i++) {
			memset(vis, false, sizeof(vis));
			ans += dfs(i);				// 为每一个i找匹配.
		}
		if (ans == n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}