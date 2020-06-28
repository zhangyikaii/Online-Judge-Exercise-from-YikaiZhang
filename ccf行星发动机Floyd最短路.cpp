//#include <bits/stdc++.h>
//using namespace std;
//
//int wei[10010];
//int gra[10010][10010];
//
//#define For(i, s, e) for(int i = s; i <= e; ++i)
//#define INF 0x7ffffff
//
//int main() {
//	int n, m, k;
//	int a, b, w;
//	cin >> n >> m >> k;
//
//	for (int i = 1; i <= n; ++i) {
//		cin >> wei[i];
//	}
//
//	For(i, 1, n) {
//		For(t, 1, n) {
//			gra[i][t] = INF;
//		}
//	}
//
//	for (int i = 1; i <= m; ++i) {
//		cin >> a >> b >> w;
//		if (a != b) {
//			gra[a][b] = w;
//			gra[b][a] = w;
//		}
//	}
//
//	for (int t = 1; t <= n; ++t) {
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				if (t != i && i != j && t != j && gra[i][j] > gra[i][t] + gra[t][j]) {
//					gra[i][j] = gra[i][t] + gra[t][j];
//				}
//			}
//		}
//	}
//
//	For(i, 1, n) {
//		For(j, 1, n) {
//			if (wei[j] == 0)
//				gra[i][j] = INF;
//		}
//		sort(&gra[i][1], &gra[i][1] + n);
//		int sum = 0, endd = k;
//		if (wei[i] == 1)
//			--endd;
//		for (int j = 1; j <= endd; ++j) {
//			if (gra[i][j] == INF)
//				break;
//			
//			sum += gra[i][j];
//		}
//		cout << sum << endl;
//	}
//
//	return 0;
//}
//
///*
//
//7 6 2
//1 0 1 0 1 1 0
//1 4 1
//1 2 3
//2 4 4
//2 3 5
//2 5 7
//6 7 5
//
//
//*/


#include <bits/stdc++.h>
using namespace std;
struct E
{
	int v, w;
	E() { }
	E(int vv, int ww) : v(vv), w(ww) { }
	bool operator < (const E& b)const {
		return w > b.w;
	}
};
int n, m, k;
int ff[10000 + 10];
priority_queue<int, vector<int>, greater<int> > d[10000];
vector<E> edge[10000];


void dijkstra(int k)
{
	priority_queue<E> Q;
	int dis[10000];

	// 记住啊, dis全部为 INF, 起点设为 0, 放入起点.
	// 当优先队列不空的时候, 拿出, 令为tmp, 如果used[tmp], continue;
	// 对于tmp的所有邻居nei, 如果到拿出的这个点的距离加这一边的距离 < 直接到nei的dis, 就更新, 并把更新的结点id和距离放入队列.
	for (int i = 0; i < n; i++)
		dis[i] = 0x3f3f3f3f;
	dis[k] = 0;
	Q.push(E(k, 0));
	while (!Q.empty())
	{
		E t = Q.top();
		Q.pop();
		if (t.w != dis[t.v])
			continue;

		d[t.v].push(t.w);			// d自己就是一个堆, 存了t.v到其他的最小距离.

		// Dijkstra 从优先队列里面拿出来的时候就已经有: 当前点到拿出来的这个点的最小距离是t.w
		// 这里其实很巧妙了. 因为你到我的最短路径, 也一定是我到你的最短路径, bidirectional.
		int m = edge[t.v].size();
		int u, w;
		for (int i = 0; i < m; i++)
		{
			u = edge[t.v][i].v;
			w = edge[t.v][i].w;
			if (dis[u] > dis[t.v] + w)
				dis[u] = dis[t.v] + w,
				Q.push(E(u, dis[u]));
		}
	}
}

// 即使是部分(大多数)点之间的最短路, 也不要Floyd, 上DIjkstra
// 题目要求的是任一据点到最近k个行星发动机据点的最短路之和，于是我们可以求k个行星发动机据点的最短路，对啊! 求k个行星发动机的最短路径树就可以了.


int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int num = 0, x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x)
			ff[num++] = i;
	}
	int u, v, w;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		u--; v--;
		edge[u].push_back(E(v, w));
		edge[v].push_back(E(u, w));
	}
	for (int i = 0; i < num; i++)
		dijkstra(ff[i]);
	long long ans;


	for (int i = 0; i < n; i++) {
		int cnt = k;
		ans = 0;
		while (!d[i].empty() && cnt--) {
			ans += d[i].top();
			d[i].pop();
		}
		printf("%lld\n", ans);
	}

	return 0;
}