#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>

#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

const int maxn = 1000000 + 1, maxm = 2000000 + 1, INF = 0x7f7f7f7f, MOD = 100003;
vector<int> G[maxn];						// 注意啦
int dep[maxn]; 
bool vis[maxn];
int cnt[maxn];

// 图还可以这样用vector存/xk (无权图)

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);					// 记住是push_back
		G[y].push_back(x);
	}

	queue<int>Q;
	dep[1] = 0;
	vis[1] = 1;
	Q.push(1); 
	cnt[1] = 1;

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i = 0; i < G[x].size(); i++) {
			int t = G[x][i];
			if (!vis[t]) { 
				vis[t] = 1;
				dep[t] = dep[x] + 1;
				Q.push(t);
			}
			// 关键!
			// 最短路肯定要经过上层结点, 这是下一层 => 加上去就可以了.
			// 一个点最短路一定经过了一个层数比它少一的结点（否则不是最短路）。
			// 所以用每个相邻且层数比当前结点层数少一的点更新当前点的路径跳数即可。

			if (dep[t] == dep[x] + 1) { 
				cnt[t] = (cnt[t] + cnt[x]) % MOD;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}
// 60分自己写的:
//#define in(a) a=read()
//
//struct Edge {
//	int to, next, w;
//	Edge() : w(1) { }
//};
//
//struct Data {
//	int x, y;
//	Data() {}
//	Data(int a, int b) : x(a), y(b) { }
//};
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//using namespace std;
//#define MAXN 1000010
//#define MAXM 2000010
//#define INF 0xfffffff
//
//int n, m, cnt = 0;
//int head[MAXN], curMin[MAXN], ans[MAXN] = { 0 };
//bool vis[MAXN] = { false };
//Edge edge[MAXM];
//
//void add(int a, int b) {
//	edge[++cnt].next = head[a];
//	head[a] = cnt;
//
//	edge[cnt].to = b;
//}
//
//int main() {
//	for (int i = 1; i < MAXN; ++i) {
//		curMin[i] = INF;
//	}
//	int aTmp, bTmp;
//	Data tmp;
//	in(n);
//	in(m);
//	
//	for (int i = 1; i <= m; ++i) {
//		in(aTmp);
//		in(bTmp);
//		add(aTmp, bTmp);
//		add(bTmp, aTmp);
//	}
//
//	queue<Data> q;
//	q.push(Data(1, 0));
//	vis[1] = true;
//	while (!q.empty()) {
//		tmp = q.front();
//		q.pop();
//		vis[tmp.x] = true;
//		if (curMin[tmp.x] > tmp.y) {
//			ans[tmp.x] = 1;
//			curMin[tmp.x] = tmp.y;
//		}
//		else if (curMin[tmp.x] == tmp.y)
//			++ans[tmp.x];
//
//		for (int i = head[tmp.x]; i != 0; i = edge[i].next) {
//			if (vis[edge[i].to] == false) {
//				q.push(Data(edge[i].to, tmp.y + 1));
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		printf("%d\n", ans[i]);
//	}
//
//
//	return 0;
//}