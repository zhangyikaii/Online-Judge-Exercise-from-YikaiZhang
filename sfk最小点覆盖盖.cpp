//树形DP
//树的最小点覆盖
//f[x][1]以x为根的子树在x上放置的士兵的最少所需的士兵数目
//f[x][0]以x为根的子树x上不放置的士兵的最少所需的士兵数目
//状态转移方程：
//如果当前节点选取，则其子节点可选可不选dp[root][1] += min(dp[tree[root][i]][1],dp[tree[root][i]][0]) ;
//如果当前节点不选，则其子节点必须选    dp[root][0] += dp[tree[root][i]][1] ;
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

vector<int> tree[100010];
int fa[100010], n, dp[100010][2];

void dfs(int root) {
	dp[root][0] = 0;
	dp[root][1] = 1;
	FOR(i, 0, tree[root].size()) {
		dfs(tree[root][i]);
	}
	FOR(i, 0, tree[root].size()) {
		dp[root][1] += min(dp[tree[root][i]][1], dp[tree[root][i]][0]);
		dp[root][0] += dp[tree[root][i]][1];
	}
}
int main() {
	FOR(i, 0, 100010)
		fa[i] = -1;
	int n = 0;
	char buf[100010] = "";
	int tmp;
	int res = 0;

	// 输入:
	while (cin.getline(buf, 100010)) {
		int i = 0, flag = 0, father = 0;

		++n;
		if (buf[0] == '\0')
			continue;

		for (i = 0; buf[i] != '\0';) {
			if (buf[i] == ' ') {
				++i;
				continue;
			}
			tmp = atoi(buf + i);

			if (flag == 0) {
				flag = 1;
				father = tmp;
				tree[father].clear();
			}
			else {
				tree[father].push_back(tmp);
				fa[tmp] = father;
			}
			while (buf[i] != '\0' && buf[i] != ' ')
				++i;
		}

		memset(buf, 0, sizeof(buf));
	}

	int a = 1;
	while (fa[a] != -1) a = fa[a];
	dfs(a);
	printf("I have read the rules about plagiarism punishment\n");
	printf("%d\n", min(dp[a][0], dp[a][1]));

	return 0;
}
