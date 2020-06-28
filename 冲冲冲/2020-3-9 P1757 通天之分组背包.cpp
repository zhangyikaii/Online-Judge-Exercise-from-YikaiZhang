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

int m, n;
int arr[1010], brr[1010];
int group[110];
int dp[1010];
int groupNum;
int indexMap[110][110];

int main() {
	// 分组背包模板题:
	in(m), in(n);
	int g = 0;
	For(i, 1, n + 1) {
		in(arr[i]), in(brr[i]), in(g);
		++group[g];
		indexMap[g][group[g]] = i;
		groupNum = max(groupNum, g);
	}

	For(i, 1, groupNum + 1) {
		for (int v = m; v >= 0; --v) {
			For(j, 1, group[i] + 1) {
				int idx = indexMap[i][j];
				if (v - arr[idx] >= 0)
					dp[v] = max(dp[v], dp[v - arr[idx]] + brr[idx]);
			}
		}
	}

	printf("%d\n", dp[m]);

	// 抄了一遍题解, 这个从分组里面第i个到总输入第几个的映射很妙.

	return 0;
}